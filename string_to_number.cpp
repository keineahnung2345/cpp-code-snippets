#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

//https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
//http://www.cplusplus.com/reference/string/stoi/

//g++ string_to_number.cpp -std=c++11

int main(){
    //to double
    std::string sd = "123.456789123";
    std::cout << std::stod(sd) << std::endl; //123.457
    std::cout << std::stold(sd) << std::endl; //123.457
    std::stringstream ss;
    ss << std::fixed << std::setprecision(10) << sd;
    std::string str = ss.str();
    std::cout << str << std::endl; //123.456789123

    //to int
    std::string si = "123456";
    std::cout << std::stoi(si, nullptr) << std::endl;
    return 0;
}
