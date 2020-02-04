#include <iostream>
  
int square(int x){
    return x * x;
}

//https://www.geeksforgeeks.org/function-pointer-in-c/

int main(){
    int (*fnc_ptr)(int) = &square;
    std::cout << (*fnc_ptr)(10) << std::endl;

    int (*fnc_ptr2)(int) = square;
    std::cout << fnc_ptr2(10) << std::endl;
    return 0;
}

/*
100
100
*/
