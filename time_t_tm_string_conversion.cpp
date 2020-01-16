#include <stdio.h>
#include <time.h>
#include <string.h>
#include <string>
#include <assert.h>

//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
//https://www.runoob.com/w3cnote/cpp-time_t.html
//https://bryceknowhow.blogspot.com/2013/10/cc-gmtimemktimetimetstruct-tm.html
//https://stackoverflow.com/questions/16344748/why-gmtime-and-localtime-give-me-the-same-result
//https://stackoverflow.com/questions/11213326/how-to-convert-a-string-variable-containing-time-to-time-t-type-in-c

char fmt[] = "%Y-%m-%d-%H:%M:%S";

std::string time_t_to_string(time_t timer, bool local){
    struct tm *tm_info_tmp, tm_info;
    char time_char_arr[100];
    std::string time_str;

    if(!local){
        tm_info_tmp = gmtime(&timer);
    }else{
        tm_info_tmp = localtime(&timer);
    }
    //need to copy the value from tm_info_tmp to another variable, ow it will be overwritten later
    memcpy(&tm_info, tm_info_tmp, sizeof(tm_info));

    strftime(time_char_arr, 100, fmt, &tm_info);
    //puts(time_char_arr);

    time_str = std::string(time_char_arr);

    return time_str;
}

time_t string_to_time_t(std::string time_str){
    struct tm tm_info;
    time_t timer;

    //from string to char array to struct tm
    strptime(time_str.c_str(), fmt, &tm_info);

    //from struct tm to time_t
    timer = mktime(&tm_info);

    return timer;
}

int main()
{
    time_t timer, timer_back;
    std::string time_str;
    bool isLocal;

    time(&timer);
    printf("time_t                         :%ld, %s",(long int)timer, ctime(&timer));

    //use GMT
    isLocal = false;
    printf("\n%s\n", isLocal ? "local: " : "global: ");
    time_str = time_t_to_string(timer, isLocal);
    printf("%s\n", time_str.c_str());
    timer_back = string_to_time_t(time_str);
    //wrong, current version doesn't consider timezone
    printf("time_t back                    :%ld, %s",(long int)timer_back, ctime(&timer_back));
//    assert((timer_back == timer) && "time_t before and after converting are different!");

    //use local time
    isLocal = true;
    printf("\n%s\n", isLocal ? "local: " : "global: ");
    time_str = time_t_to_string(timer, isLocal);
    printf("%s\n", time_str.c_str());
    timer_back = string_to_time_t(time_str);
    printf("time_t back                    :%ld, %s",(long int)timer_back, ctime(&timer_back));
//    assert((timer_back == timer) && "time_t before and after converting are different!");

    return 0;
}

/*
time_t                         :1579157697, Thu Jan 16 14:54:57 2020

global: 
2020-01-16-06:54:57
time_t back                    :1579128897, Thu Jan 16 06:54:57 2020

local: 
2020-01-16-14:54:57
time_t back                    :1579157697, Thu Jan 16 14:54:57 2020
*/
