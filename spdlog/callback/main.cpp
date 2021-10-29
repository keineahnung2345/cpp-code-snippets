#include <iostream>

#include "log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"

using namespace std;

void buildLoggerSpd();
void buildLoggerCout();

int main(int argc, char** argv) {
    bool useSpd = true;
    if (useSpd) {
        buildLoggerSpd();
    }
    else {
        buildLoggerCout();
    }

    std::string s = "hello";
    int i = 2;
    float f = 3.14;
    bool b = true;
    log_info(std::format("s: {}, i: {}, f: {}, b: {}", s, i, f, b));
    //[ info] s: hello, i: 2, f: 3.14, b: true

    return 0;
}

void buildLoggerSpd() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info);
    console_sink->set_pattern("[%^%5l%$] %v"); //not showing datetime

    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("../../logs/daily.txt", 0, 0);
    daily_sink->set_level(spdlog::level::trace);
    daily_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e.%z] [%n] [%^%5l%$] [%5t] [%10!s:%4#:%15!!] %v");

    auto logger = std::make_shared<spdlog::logger>(spdlog::logger("multi_sink", { console_sink, daily_sink }));
    logger->set_level(spdlog::level::debug);
    logger->flush_on(spdlog::level::warn);
    spdlog::flush_every(std::chrono::seconds(3));
    spdlog::register_logger(logger);

    setLogDebug([logger](const std::string& str) {
        return logger->debug(str);
        });
    setLogInfo([logger](const std::string& str) {
        //return (*(logger.get()).*(static_cast<void(spdlog::logger::*)(const std::string&)>(&spdlog::logger::info<std::string>)))(str);
        return logger->info(str);
        });
    setLogWarn([logger](const std::string& str) {
        return logger->warn(str);
        });
    setLogError([logger](const std::string& str) {
        return logger->error(str);
        });

    //setupLogFns([]<typename... Args>(spdlog::string_view_t&& fmt, Args&&... args) {
    //    return logger->info(std::forward<spdlog::string_view_t>(fmt), std::forward<Args>(args)...);
    //});

    //setupLogFns([](std::ostream& os, const std::string& str) {
    //    return (std::cout << str);
    //    });
    return;
}

void buildLoggerCout() {
    setLogDebug([](const std::string& str) {
        std::cout << str << std::endl;
        });
    setLogInfo([](const std::string& str) {
        std::cout << str << std::endl;
        });
    setLogWarn([](const std::string& str) {
        std::cout << str << std::endl;
        });
    setLogError([](const std::string& str) {
        std::cout << str << std::endl;
        });
}