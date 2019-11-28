#include <stdio.h>

//https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool

int main(){
    bool x = true;
    printf("%s\n", x ? "true" : "false");
    x = false;
    printf("%s\n", x ? "true" : "false");
    return 0;
}
