#include <stdio.h>
#include <time.h>

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
