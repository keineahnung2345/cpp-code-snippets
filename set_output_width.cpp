#include <iomanip>
#include <iostream>

int main(){
    std::cout << std::setw(4) << 3 << std::endl;
    std::cout << 2 << std::endl; //setw won't work on this line
    std::cout << std::setw(6) << 1 << std::endl;
    std::cout << std::setw(5);
    std::cout << 0 << std::endl;
    std::cout << -1 << std::endl; //setw won't work on this line
    return 0;
}

/*
   3
2
     1
    0
-1
*/
