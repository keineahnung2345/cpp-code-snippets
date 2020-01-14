#include <stdio.h>
#include <time.h>
#include <string.h>

//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
//https://www.runoob.com/w3cnote/cpp-time_t.html
//https://bryceknowhow.blogspot.com/2013/10/cc-gmtimemktimetimetstruct-tm.html
//https://stackoverflow.com/questions/16344748/why-gmtime-and-localtime-give-me-the-same-result

int main()
{
    time_t timer, timer_back;
    struct tm *tm_info_tmp, tm_info_local, tm_info_gm;
    struct tm tb;
    char buffer[100];
    char fmt[] = "%Y-%m-%d-%H:%M:%S";

    time(&timer);
    printf("time_t         :%ld, %s",(long int)timer, ctime(&timer));

    tm_info_tmp = gmtime(&timer);
    //need to copy the value from tm_info_tmp to another variable, ow it will be overwritten later
    memcpy(&tm_info_gm, tm_info_tmp, sizeof(tm_info_gm));
    tm_info_tmp = localtime(&timer);
    memcpy(&tm_info_local, tm_info_tmp, sizeof(tm_info_local));

    printf("GMT tm         :");
    strftime(buffer, 100, fmt, &tm_info_gm);
    puts(buffer);

    printf("local time tm  :");
    strftime(buffer, 100, fmt, &tm_info_local);
    puts(buffer);

    timer_back = mktime(&tm_info_gm);
    printf("time_t back    :%ld, %s", (long int)timer_back, ctime(&timer_back));

    return 0;
}

/*
time_t         :1578974895, Tue Jan 14 12:08:15 2020
GMT tm         :2020-01-14-04:08:15
local time tm  :2020-01-14-12:08:15
time_t back    :1578946095, Tue Jan 14 04:08:15 2020
*/
