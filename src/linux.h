#ifndef H_LINUX_H
#define H_LINUX_H

#include <string>
#include <linux/kernel.h>
#include <sys/sysinfo.h>
#include <vector>

std::string GetHostName();
long GetUptime();
std::vector<std::tuple<std::string, std::string>> GetLocalIpAddrs();


#endif
