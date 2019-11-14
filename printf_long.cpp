#include <stdio.h>

//https://stackoverflow.com/questions/38561/what-is-the-argument-for-printf-that-formats-a-long

int main(){
    long l = -123456789123;
    unsigned long lu = 1234567891234;
    printf("%ld\n", l);
    printf("%lu\n", lu);
    return 0;
}
