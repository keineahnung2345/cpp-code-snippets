#include <stdio.h>
  
const int f1(){
    return 3;
};

const char* f2(){
    return "abc";
};

int main(){
    int x = f1();
    //error: cannot initialize a variable of type 'char *' with an rvalue of type 'const char *'
    //char* s = f2();
    const char* s = f2();
    printf("%d\n", x);
    printf("%s\n", s);

    x = 2;
    //error: read-only variable is not assignable
    //s[0] = 'd';
    printf("%d\n", x);
    return 0;
}
