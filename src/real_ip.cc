#include "src/real_ip.h"
#include "curl_easy.h"
#include <sstream>

namespace {
  constexpr char EXTERNAL_IP_SERVICE[] = "http://api.ipify.org/";
}

std::string GetRealIp() {
  std::ostringstream stream;
  curl::curl_ios<std::ostringstream> ios(stream);
  curl::curl_easy easy(ios);
  easy.add<CURLOPT_URL>(EXTERNAL_IP_SERVICE);

  try {
    easy.perform();
  } catch (curl::curl_easy_exception &error) {
    std::cerr << error.what() << std::endl;
    return "NO_IP";
  }

  return stream.str();
}
