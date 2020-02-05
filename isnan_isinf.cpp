#include <cmath>
#include <iostream>
#include <iomanip>

int main(){
    std::cout << std::setw(10) << std::left << "0.0/0.0" << " is nan? " << std::isnan(0.0/0.0) << ", is inf? " << std::isinf(0.0/0.0) << std::endl;
    std::cout << std::setw(10) << std::left << "sqrt(-1.0)" << " is nan? " << std::isnan(sqrt(-1.0)) << ", is inf? " << std::isinf(sqrt(-1.0)) << std::endl;
    std::cout << std::setw(10) << std::left << "log(-1.0)" << " is nan? " << std::isnan(log(-1.0)) << ", is inf? " << std::isinf(log(-1.0)) << std::endl;
    std::cout << std::setw(10) << std::left << "1.0/0.0" << " is nan? " << std::isnan(1.0/0.0) << ", is inf? " << std::isinf(1.0/0.0) << std::endl;
    std::cout << std::setw(10) << std::left << "-1.0/0.0" << " is nan? " << std::isnan(-1.0/0.0) << ", is inf? " << std::isinf(-1.0/0.0) << std::endl;
    return 0;
}

/*
0.0/0.0    is nan? 1, is inf? 0
sqrt(-1.0) is nan? 1, is inf? 0
log(-1.0)  is nan? 1, is inf? 0
1.0/0.0    is nan? 0, is inf? 1
-1.0/0.0   is nan? 0, is inf? 1
*/
