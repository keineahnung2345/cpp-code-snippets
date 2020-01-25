#include <iostream>
  
const int f1(){
    return 3;
};

const char* f2(){
    return "abc";
};

int main(){
    int x = f1();
    //Error: cannot initialize a variable of type 'char *' with an rvalue of type 'const char *'
    //char* s = f2();
    const char* s = f2();
    std::cout << x << std::endl;
    std::cout << s << std::endl;
    return 0;
}
