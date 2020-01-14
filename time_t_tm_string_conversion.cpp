#include <stdio.h>
#include <time.h>
#include <string.h>

//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
//https://www.runoob.com/w3cnote/cpp-time_t.html
//https://bryceknowhow.blogspot.com/2013/10/cc-gmtimemktimetimetstruct-tm.html
//https://stackoverflow.com/questions/16344748/why-gmtime-and-localtime-give-me-the-same-result
//https://stackoverflow.com/questions/11213326/how-to-convert-a-string-variable-containing-time-to-time-t-type-in-c

int main()
{
    time_t timer, timer_back;
    struct tm *tm_info_tmp;
    struct tm tm_info_local, tm_info_gm;
    struct tm tm_info_local_back, tm_info_gm_back;
    char str_local[100], str_gm[100];
    char fmt[] = "%Y-%m-%d-%H:%M:%S";

    time(&timer);
    printf("time_t                         :%ld, %s",(long int)timer, ctime(&timer));

    tm_info_tmp = gmtime(&timer);
    //need to copy the value from tm_info_tmp to another variable, ow it will be overwritten later
    memcpy(&tm_info_gm, tm_info_tmp, sizeof(tm_info_gm));
    tm_info_tmp = localtime(&timer);
    memcpy(&tm_info_local, tm_info_tmp, sizeof(tm_info_local));

    printf("GMT tm                         :");
    strftime(str_gm, 100, fmt, &tm_info_gm);
    puts(str_gm);

    printf("local time tm                  :");
    strftime(str_local, 100, fmt, &tm_info_local);
    puts(str_local);

    //from string to struct tm
    strptime(str_gm, fmt, &tm_info_gm_back);
    strptime(str_local, fmt, &tm_info_local_back);

    //from struct tm to time_t
    timer_back = mktime(&tm_info_gm_back);
    printf("time_t back from GMT tm        :%ld, %s", (long int)timer_back, ctime(&timer_back));

    timer_back = mktime(&tm_info_local_back);
    printf("time_t back from local time tm :%ld, %s", (long int)timer_back, ctime(&timer_back));

    return 0;
}

/*
time_t                         :1578981505, Tue Jan 14 13:58:25 2020
GMT tm                         :2020-01-14-05:58:25
local time tm                  :2020-01-14-13:58:25
time_t back from GMT tm        :1578952705, Tue Jan 14 05:58:25 2020
time_t back from local time tm :1578981505, Tue Jan 14 13:58:25 2020
*/
