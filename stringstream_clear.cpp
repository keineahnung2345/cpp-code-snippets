#include <iostream>
#include <iomanip>
#include <sstream>

//https://stackoverflow.com/questions/20731/how-do-you-clear-a-stringstream-variable
 
int main() {
    std::stringstream ss;
    float f1 = 0.0f;
    for(size_t i = 0; i < 3; ++i) {
        ss.str(std::string());
        ss << std::fixed << std::setprecision(2) << "_" << f1 << "_";
        std::cout << ss.str() << std::endl;
        f1 += 1.0f;
    }
    return 0;
}

/**
_0.00_
_1.00_
_2.00_
**/

/**
If commenting `ss.str(std::string());`:
_0.00_
_0.00__1.00_
_0.00__1.00__2.00_
**/
