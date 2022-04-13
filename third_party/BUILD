cc_library(
  name = "tgbot",
  srcs = glob(["tgbot-cpp/src/Api.cpp"]),
  hdrs = glob([
    "tgbot-cpp/include/tgbot/**/*.h",
  ]),
  strip_include_prefix = "tgbot-cpp/include",
  visibility = ["//visibility:public"],
  copts = ["-I third_party/tgbot/include"],
)
