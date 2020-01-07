#include <stdio.h>
#include <time.h>

//https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811

int main()
{
    time_t timer;
    struct tm* tm_info;
    char buffer[26];

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    return 0;
}

/*
2020-01-07 11:23:09
*/
