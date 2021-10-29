#include "log.h"

LogFnCallback log_debug_fp;
LogFnCallback log_info_fp;
LogFnCallback log_warn_fp;
LogFnCallback log_error_fp;

void setLogDebug(std::function<void(const std::string&)>&& fn) {
    log_debug_fp = std::forward<std::function<void(const std::string&)>>(fn);
}
void setLogInfo(std::function<void(const std::string&)>&& fn) {
    log_info_fp = std::forward<std::function<void(const std::string&)>>(fn);
}
void setLogWarn(std::function<void(const std::string&)>&& fn) {
    log_warn_fp = std::forward<std::function<void(const std::string&)>>(fn);
}
void setLogError(std::function<void(const std::string&)>&& fn) {
    log_error_fp = std::forward<std::function<void(const std::string&)>>(fn);
}

//https://stackoverflow.com/questions/17644133/function-that-accepts-both-lvalue-and-rvalue-arguments
//so that these functions can accept both lvalue and rvalue
void log_debug(std::string&& s) {
    log_debug_fp(s);
}
void log_debug(const std::string& s) {
    log_debug_fp(s);
}
void log_info(std::string&& s) {
    log_info_fp(s);
}
void log_info(const std::string& s) {
    log_info_fp(s);
}
void log_warn(std::string&& s) {
    log_warn_fp(s);
}
void log_warn(const std::string& s) {
    log_warn_fp(s);
}
void log_error(std::string&& s) {
    log_error_fp(s);
}
void log_error(const std::string& s) {
    log_error_fp(s);
}

//template<typename... Args>
//using LogFnCallbackT = std::function<void(spdlog::string_view_t&&, Args&&...)>;
//template<typename... Args>
//inline LogFnCallbackT<Args...> log_infoT;
//template<typename... Args>
//void setupLogFns(std::function<void(spdlog::string_view_t&&, Args&&...)> fn) {
//    log_infoT = fn;
//}

//void setupLogFns(std::function<std::ostream& (std::ostream& os, const std::string& str)> fn) {
//    log_info = fn;
//}