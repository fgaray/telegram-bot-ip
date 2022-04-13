cc_library(
  name = "tgbot",
  srcs = glob(["tgbot-cpp/src/**/*.cpp"]),
  hdrs = glob([
    "tgbot-cpp/include/tgbot/**/*.h",
  ]),
  strip_include_prefix = "tgbot-cpp/include",
  visibility = ["//visibility:public"],
  copts = ["-I third_party/tgbot/include", "-std=c++20"],
  linkopts = ["-lboost_system -lssl -lcrypto -lpthread"],
)


cc_library(
  name = "curlcpp",
  srcs = glob(["curlcpp/src/**/*.cpp"]),
  hdrs = glob([
    "curlcpp/include/**/*.h",
  ]),
  strip_include_prefix = "curlcpp/include",
  visibility = ["//visibility:public"],
  copts = ["-I third_party/curlpp/include"],
  linkopts = ["-lcurl"],
)
