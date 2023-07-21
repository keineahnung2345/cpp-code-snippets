#include <iostream>
#include <chrono>

std::string unixTime2Timestamp(unsigned long long unix_time) {
    std::chrono::system_clock::time_point p0{ std::chrono::seconds{
        unix_time } };
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(p0);
    // std::ctime = std::asctime(std::localtime(time)) so timezone will be
    // considered
    std::string timestamp  = std::ctime(&epoch_time);
    timestamp.pop_back();  // discard trailing '\n'
    return timestamp;
}

int main() {
    std::cout << unixTime2Timestamp(1689911880) << std::endl;
    // Fri Jul 21 03:58:00 2023
    return 0;
}
