#include <iostream>
#include <ctime>

//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

void get_time(int& year, int& month, int& day, int& hour, int& min, int& sec) {
    time_t now = time(NULL);
    struct tm* ltm = localtime(&now);

    year = ltm->tm_year + 1900; // Year is # years since 1900
    month = ltm->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    min = ltm->tm_min;
    sec = ltm->tm_sec;
}

int main() {
    int year, month, day, hour, min, sec;
    get_time(year, month, day, hour, min, sec);
    std::cout << "year: " << year << std::endl;
    std::cout << "month: " << month << std::endl;
    std::cout << "day: " << day << std::endl;
    std::cout << "hour: " << hour << std::endl;
    std::cout << "min: " << min << std::endl;
    std::cout << "sec: " << sec << std::endl;
    return 0;
}

/**
year: 2021
month: 8
day: 30
hour: 1
min: 50
sec: 10
**/
