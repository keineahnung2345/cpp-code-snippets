#include <iostream>
#include <limits>
#include <cmath>

//https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon

int main(){
    double eps = std::numeric_limits<double>::epsilon();
    double d1 = 1.0/std::sqrt(5.0)/std::sqrt(5.0);
    double d2 = 0.2;

    if(d1 == d2){
        std::cout << d1 << " is equal to " << d2 << std::endl;
    }else{
        std::cout << d1 << " is not equal to " << d2 << std::endl;
    }

    if((d1 == d2) < eps){
        std::cout << d1 << " is similar to " << d2 << std::endl;
    }
    return 0;
}
