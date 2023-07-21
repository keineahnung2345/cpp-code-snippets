#include <iostream>
#include <chrono>

// https://stackoverflow.com/questions/6012663/get-unix-timestamp-with-c
// https://stackoverflow.com/questions/57943837/how-to-convert-epoch-time-to-time-point
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

int main() {
    std::cout << getUnixTime() << std::endl; // 1689911880
    return 0;
}
