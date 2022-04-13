A telegram bot that will respond with the external IP of the server that is
running the bot.

# Clonning

```
git clone --recursive https://github.com/fgaray/telegram-bot-ip.git
```


# Compiling

You need to have installed the same depencies than [tgbot-cpp](https://github.com/reo7sp/tgbot-cpp)

```
sudo apt-get install g++ make binutils cmake libssl-dev libboost-system-dev zlib1g-dev
```

Plus you will need to have [bazel](https://docs.bazel.build/versions/main/install-ubuntu.html) installed.

To compile/run, use this command

```
bazel run //src:main -- --token=YOUR_TOKEN
```

Replace YOUR_TOKEN with the token of the telegram bot you want to use.
