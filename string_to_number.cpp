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

    //to float
    std::string sf = "123.456";
    std::cout << std::stof(sf) << std::endl; //123.456

    //to int
    std::string si = "123456";
    std::cout << std::stoi(si, nullptr) << std::endl; //123456
    std::cout << std::stoi(si) << std::endl; //123456

    //to long
    std::string sl = "1234567890123456";
    std::cout << std::stol(sl) << std::endl; //1234567890123456

    return 0;
}
