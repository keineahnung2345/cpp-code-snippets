#include <stdio.h>

int main(){
    bool x = true;
    printf("%s\n", x ? "true" : "false");
    x = false;
    printf("%s\n", x ? "true" : "false");
    return 0;
}
