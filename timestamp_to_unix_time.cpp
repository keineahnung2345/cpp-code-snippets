#include <chrono>
#include <iomanip>  // std::get_time
#include <iostream>
#include <sstream>

unsigned long long getUnixTime(std::chrono::system_clock::time_point p0 =
                                   std::chrono::system_clock::time_point{
                                       std::chrono::seconds{ 0 } }) {
    if(p0 ==
       std::chrono::system_clock::time_point{ std::chrono::seconds{ 0 } }) {
        p0 = std::chrono::system_clock::now();
    }
    return std::chrono::duration_cast<std::chrono::seconds>(
               p0.time_since_epoch())
        .count();
}

// https://stackoverflow.com/questions/21021388/how-to-parse-a-date-string-into-a-c11-stdchrono-time-point-or-similar
unsigned long long timestamp2UnixTime(std::string timestamp) {
    std::tm           timeinfo = {};
    std::stringstream ss(timestamp);
    ss >> std::get_time(&timeinfo, "%a %b %d %H:%M:%S %Y");
    time_t epoch = mktime(&timeinfo);
    auto   p0    = std::chrono::system_clock::from_time_t(epoch);
    return getUnixTime(p0);
}

int main() {
    std::cout << timestamp2UnixTime("Fri Jul 21 09:27:58 2023") << std::endl;
    // 1689931678
    return 0;
}
