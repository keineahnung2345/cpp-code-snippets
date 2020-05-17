// complex::real example
#include <iostream>     // std::cout
#include <complex>      // std::complex

int main (){
    std::complex<double> org(0.0,0.0), p1(3.0, 4.0);
    std::cout << "Real part: " << p1.real() << ", imaginary part: " << p1.imag() << std::endl;
    std::cout << "Distance to original point: " << std::abs(p1-org) << std::endl;
    return 0;
}

/*
Real part: 3, imaginary part: 4
Distance to original point: 5
*/
