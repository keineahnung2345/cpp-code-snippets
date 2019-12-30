#include <stdio.h>

//https://stackoverflow.com/questions/1041866/what-is-the-effect-of-extern-c-in-c
//https://stackoverflow.com/questions/25210629/what-does-this-nm-output-mean

extern "C" void show(const char* s){
    printf("%s\n", s);
};

//extern "C" suppresses mangling, so overloading can't be performed
//error: conflicting declaration of C function ‘void show(double)’
/*
extern "C" void show(double d){
    printf("%lf\n", d);
};
*/

//without extern "C", we can do overloading
void show(int i){
    printf("%d\n", i);
};

void show(float f){
    printf("%f\n", f);
};
  
int main() 
{ 
    const char* s = "GeeksforGeeks";
    int i = 3;
    float f = 3.5;
    show(s); 
    show(i);
    show(f);
    return 0; 
} 

/*
output from "nm a.out | grep show":
00000000004005e6 T show
0000000000400623 T _Z4showf
0000000000400601 T _Z4showi

We can see that the name of the function show declared using extern "C" is not mangled.
*/
