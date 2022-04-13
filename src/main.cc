#include <string>
#include <limits>

#include "tgbot/tgbot.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "src/linux.h"
#include "src/real_ip.h"

ABSL_FLAG(std::string, token, "YOUR_TOKEN", "The Telegram's token bot");

int main(int argc, char *argv[]) {
  absl::ParseCommandLine(argc, argv);

  TgBot::Bot bot(absl::GetFlag(FLAGS_token));

  bot.getEvents().onCommand("ping", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, "Pong!");
  });

  bot.getEvents().onCommand("hostname", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, GetHostName());
  });

  bot.getEvents().onCommand("sysinfo", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, "Uptime: " + std::to_string(GetUptime() / 60.0 / 60.0) + " hours");
  });

  bot.getEvents().onCommand("ip", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, GetRealIp());
  });

  bot.getEvents().onCommand("localip", [&bot](TgBot::Message::Ptr message) {
    auto ips = GetLocalIpAddrs();
    bot.getApi().sendMessage(message->chat->id, std::to_string(ips.size()) + " interfaces");
    for (const auto &[interface, ip]: ips) {
      std::cout << ip << std::endl;
      bot.getApi().sendMessage(message->chat->id, interface + ": " + ip);
    }
  });

  try {
    std::cout << "Bot username: " << bot.getApi().getMe()->username << std::endl;
    TgBot::TgLongPoll longPoll(bot);
    while (true) {
      longPoll.start();
    }
  } catch (TgBot::TgException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
