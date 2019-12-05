#include <stdio.h>

//https://stackoverflow.com/questions/38561/what-is-the-argument-for-printf-that-formats-a-long
//https://stackoverflow.com/questions/2258700/how-do-i-printf-a-long-shouldnt-this-work-li

int main(){
    long l = -123456789123;
    unsigned long lu = 1234567891234;
    printf("%ld %ld\n", l, lu);
    printf("%li %li\n", l, lu);
    printf("%lu\n", lu);
    /*
    -123456789123 1234567891234
    -123456789123 1234567891234
    1234567891234
    */
    return 0;
}
