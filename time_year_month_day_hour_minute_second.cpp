#include <iostream>
#include <chrono>

void get_time(int& year, int& month, int& day, int& hour, int& min, int& sec, 
    const bool is_local = false, const unsigned long long unixtime = 0) {
    time_t tt = time(NULL);
    if (unixtime != 0) {
        //https://stackoverflow.com/questions/32300972/how-to-properly-convert-a-unix-timestamp-string-to-time-t-in-c11
        std::chrono::system_clock::time_point tp = std::chrono::system_clock::time_point(std::chrono::seconds(unixtime));
        tt = std::chrono::system_clock::to_time_t(tp);
    }

    struct tm* mytm;
    if (is_local) {
        mytm = localtime(&tt);
    }
    else {
        mytm = gmtime(&tt);
    }

    //https://stackoverflow.com/questions/15957805/extract-year-month-day-etc-from-stdchronotime-point-in-c
    year = mytm->tm_year + 1900; // Year is # years since 1900
    month = mytm->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    day = mytm->tm_mday;
    hour = mytm->tm_hour;
    min = mytm->tm_min;
    sec = mytm->tm_sec;
}

int main(int argc, char** argv) {
    //https://www.epochconverter.com/
    unsigned long long now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    int year, month, day, hour, minute, second;
    get_time(year, month, day, hour, minute, second, false, now);
    std::cout << "UTC time:   " << year << "-" << month << "-" << day << " " <<
        hour << ":" << minute << ":" << second << std::endl;

    get_time(year, month, day, hour, minute, second, true, now);
    std::cout << "local time: " << year << "-" << month << "-" << day << " " <<
        hour << ":" << minute << ":" << second << std::endl;

    return 0;
}

//UTC time:   2021-9-7 7:46:32
//local time: 2021-9-7 15:46:47
