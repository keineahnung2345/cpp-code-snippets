#include <string>
#include <iostream>
#include <filesystem>
#include <chrono>

#include <Windows.h>

//https://stackoverflow.com/questions/1566645/filetime-to-int64
__int64 FileTimeToULL(FILETIME ft)
{
    return static_cast<__int64>(ft.dwHighDateTime) << 32 | ft.dwLowDateTime;
}

//https://stackoverflow.com/questions/20370920/convert-current-time-from-windows-to-unix-timestamp-in-c-or-c
unsigned long long FileTimeToUnixTime(FILETIME ft) {
    //Copy the low and high parts of FILETIME into a LARGE_INTEGER
    //This is so we can access the full 64-bits as an Int64 without causing an alignment fault
    LARGE_INTEGER li;
    li.LowPart = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;

    //Convert ticks since 1/1/1970 into seconds
    const __int64 UNIX_TIME_START = 0x019DB1DED53E8000; //January 1, 1970 (start of Unix epoch) in "ticks"
    const __int64 TICKS_PER_SECOND = 10000000; //a tick is 100ns
    return static_cast<unsigned long long>((li.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND);
}

//https://stackoverflow.com/questions/3729169/how-can-i-get-the-windows-system-time-with-millisecond-resolution
BOOL GetLocalTimeAsFileTime(LPFILETIME ftNowLocal)
{
    FILETIME ftNow;
    GetSystemTimeAsFileTime(&ftNow);

    //convert to local
    return FileTimeToLocalFileTime(&ftNow, ftNowLocal);
}

unsigned long long GetSystemTimeAsUnixTime()
{
    //Get the number of seconds since January 1, 1970 12:00am UTC
    //Code released into public domain; no attribution required.
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft); //returns ticks in UTC
    return FileTimeToUnixTime(ft);
}

unsigned long long GetLocalTimeAsUnixTime()
{
    FILETIME ft;
    GetLocalTimeAsFileTime(&ft);
    return FileTimeToUnixTime(ft);
}

int main(int argc, char** argv) {
    //https://www.epochconverter.com/
    double now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    //https://stackoverflow.com/questions/5212018/how-to-make-c-cout-not-use-scientific-notation
    // add std::fixed to not using scientific notation
    std::cout << "now: " << std::fixed << now << std::endl;

    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    unsigned long long ull = FileTimeToULL(ft);
    unsigned long long ut = FileTimeToUnixTime(ft);
    std::cout << "now unsigned long long: " << ull << std::endl;
    std::cout << "now unix time: " << ut << std::endl;

    unsigned long long utcTime = GetSystemTimeAsUnixTime();
    unsigned long long localTime = GetLocalTimeAsUnixTime();
    std::cout << "utcTime: " << utcTime << std::endl;
    std::cout << "localTime: " << localTime << std::endl;

    return 0;
}

//now: 1630993638.000000
//now unsigned long long : 132754672385819584
//now unix time : 1630993638
//utcTime : 1630993638
//localTime : 1631022438

/*
note:
windows time starts from 1601/01/01
unix time start from 1970/01/01
so they differ by about 369 years
(132754672385819584/10000000-1630993638)/60/60/24/365 ~= 369
*/
