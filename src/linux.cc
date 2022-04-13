#include <unistd.h>
#include <memory>

#include "src/linux.h"
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>

namespace {
constexpr size_t MAX_BUFFER = 100;
constexpr size_t MAX_ADDR_BUFFER = 100;

std::unique_ptr<struct sysinfo> GetSysInfo() {
  std::unique_ptr<struct sysinfo> s_info(new struct sysinfo);
  sysinfo(s_info.get());
  return s_info;
}

}


std::string GetHostName() {
  char *buffer = new char[MAX_BUFFER];
  gethostname(buffer, MAX_BUFFER);
  std::string str = buffer;
  delete buffer;
  return str;
}


long GetUptime() {
  auto s_info = GetSysInfo();
  return s_info->uptime;
}

std::vector<std::tuple<std::string, std::string>> GetLocalIpAddrs() {
  std::vector<std::tuple<std::string, std::string>> ips;
  struct ifaddrs *ifap = nullptr;
  getifaddrs(&ifap);

  // iterate over linked list
  for (struct ifaddrs *curr = ifap; curr->ifa_next != nullptr; curr = curr->ifa_next) {
    if (curr->ifa_addr == nullptr) {
      ips.push_back(std::make_tuple(curr->ifa_name, "NULL"));
    } else {
      char *buffer = new char[MAX_ADDR_BUFFER];
      int err = getnameinfo(curr->ifa_addr, sizeof(*(curr->ifa_addr)), buffer, MAX_ADDR_BUFFER, 0, 0, NI_NUMERICHOST);
      if (!err) {
        ips.push_back(std::make_tuple(curr->ifa_name, std::string(buffer)));
      }
      delete buffer;
    }
  }

  freeifaddrs(ifap);
  return ips;
}
