#include <iomanip>
#include <limits> //numeric_limits
#include <iostream>

//https://stackoverflow.com/questions/554063/how-do-i-print-a-double-value-with-full-precision-using-cout

int main(){
    std::cout << std::setw(4) << 3 << std::endl;
    std::cout << 2 << std::endl; //setw won't work on this line
    std::cout << std::setw(6) << 1 << std::endl;
    std::cout << std::setw(5);
    std::cout << 0 << std::endl;
    std::cout << -1 << std::endl; //setw won't work on this line
    std::cout << std::setw(5) << std::fixed << std::setprecision(2) << 3.14159;
    std::cout << std::setw(5) << std::fixed << std::setprecision(2) << 3.14159;
    std::cout << std::endl;
    
    //using std::numeric_limits
    double d = 3.14159265358979;
    float f = d;
    std::cout << std::setprecision(std::numeric_limits<float>::max_digits10) << f << std::endl;
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10) << d << std::endl;
    return 0;
}

/*
   3
2
     1
    0
-1
 3.14 3.14
3.141592741
3.14159265358979001
*/
