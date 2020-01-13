#include <time.h>
#include <string>
#include <iostream>

//https://stackoverflow.com/questions/37505001/how-do-i-convert-a-unix-timestamp-string-to-time-t-in-c11

int main()
{
    time_t timer;
    std::string timer_str;
    time_t timer_back;

    time(&timer);
    std::cout << "time_t: " << (long int)timer << std::endl;

    timer_str = std::to_string((long int)timer);
    std::cout << "convert to string: " << timer_str << std::endl;

    timer_back = (time_t)stol(timer_str);
    std::cout << "back to time_t: " << timer_back << std::endl;

    return 0;
}
