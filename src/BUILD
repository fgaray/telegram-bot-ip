cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [
    ":linux",
    ":real_ip",
    "//third_party:tgbot",
    "@com_google_absl//absl/flags:flag",
    "@com_google_absl//absl/flags:parse",
  ],
  #copts = ["-std=c++20"],
)


cc_library(
  name = "linux",
  srcs = ["linux.cc"],
  hdrs = ["linux.h"],
  copts = ["-std=c++20"],
)

cc_library(
  name = "real_ip",
  srcs = ["real_ip.cc"],
  hdrs = ["real_ip.h"],
  deps = [
    "//third_party:curlcpp",
  ],
  #copts = ["-std=c++20"],
)
