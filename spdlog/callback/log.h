#pragma once

/**
* using callback function, this design avoids including "spdlog.h" in "log.h", 
* hence avoiding every file including "log.h"
* 
* also it supports using cout as log function
**/

#include <functional>
#include <string>

void setLogDebug(std::function<void(const std::string&)>&& fn);
void setLogInfo(std::function<void(const std::string&)>&& fn);
void setLogWarn(std::function<void(const std::string&)>&& fn);
void setLogError(std::function<void(const std::string&)>&& fn);
//template<typename... Args>
//void setupLogFns(std::function<void(spdlog::string_view_t&&, Args&&...)> fn);

typedef std::function<void(const std::string&)> LogFnCallback;

void log_debug(std::string&& s);
void log_debug(const std::string& s);
void log_info(std::string&& s);
void log_info(const std::string& s);
void log_warn(std::string&& s);
void log_warn(const std::string& s);
void log_error(std::string&& s);
void log_error(const std::string& s);