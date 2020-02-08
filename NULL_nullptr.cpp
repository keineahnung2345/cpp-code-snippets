#include <iostream>
  
void f(int x){
    std::cout << "int: " << x << std::endl;
}

void f(void* x){
    std::cout << "pointer: " << x << std::endl;
}

int main(){
    f(0); //int: 0
    f(nullptr); //pointer: 0x0
    //error: call to 'f' is ambiguous
    //f(NULL);
    return 0;
}
