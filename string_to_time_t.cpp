#include <time.h>
#include <string>
#include <assert.h>

//https://stackoverflow.com/questions/11213326/how-to-convert-a-string-variable-containing-time-to-time-t-type-in-c
time_t str2time(std::string str){
    struct tm tm_info;
    strptime(str.c_str(), "%Y%m%d%H%M%S", &tm_info);
    time_t t = mktime(&tm_info);
    return t;
}

int main(){
    time_t timer;
    struct tm *tm_info;
    char buffer[100];
    std::string time_str;

    time(&timer);

    tm_info = localtime(&timer);

    strftime(buffer, 100, "%Y%m%d%H%M%S", tm_info);
    time_str = std::string(buffer);

    assert((str2time(time_str) == timer) && "time_t before and after converting are different!");

    return 0;
}
