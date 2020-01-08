#include <stdio.h>
#include <time.h>

//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811
//https://www.runoob.com/w3cnote/cpp-time_t.html

int main()
{
    time_t timer;
    struct tm *tm_info_local, *tm_info_gm;
    char buffer[100];

    time(&timer);
    printf("time_t: %s", ctime(&timer));

    tm_info_gm = gmtime(&timer);
    tm_info_local = localtime(&timer);

    strftime(buffer, 100, "GMT tm: %Y-%m-%d %H:%M:%S", tm_info_gm);
    puts(buffer);

    strftime(buffer, 100, "local time tm: %Y-%m-%d %H:%M:%S", tm_info_local);
    puts(buffer);

    return 0;
}

/*
time_t: Wed Jan  8 13:56:06 2020
GMT tm: 2020-01-08 13:56:06
local time tm: 2020-01-08 13:56:06
*/
