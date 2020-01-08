#include <time.h>
#include <stdio.h>

//https://stackoverflow.com/questions/9987562/determining-the-difference-between-dates

// Make a tm structure representing this date
tm make_tm(int year, int month, int day)
{
    tm tm = {0};
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}

int diff_in_days(time_t t1, time_t t2){
    const int seconds_per_day = 60*60*24;
    time_t difference = (t1 - t2) / seconds_per_day;
    return int(difftime(t1, t2) / seconds_per_day);
}

int main(){
    // Structures representing the two dates
    tm tm1 = make_tm(2019,12,31);
    tm tm2 = make_tm(2020,1,4);

    // Arithmetic time values.
    // On a posix system, these are seconds since 1970-01-01 00:00:00 UTC
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    printf("time1: %s", ctime(&time1));
    printf("time2: %s", ctime(&time2));
    printf("their difference in days: %d\n", diff_in_days(time1, time2));
    return 0;
}
