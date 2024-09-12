#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

//https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
//http://www.cplusplus.com/reference/string/stoi/
//https://stackoverflow.com/questions/3850558/how-to-check-to-ensure-you-have-an-integer-before-calling-atoi

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

    // when string is not guaranteed to be convertible
    char*       pEnd;
    std::string s   = "123";
    long        num = strtol(s.c_str(), &pEnd, 10);

    if(*pEnd == '\0')
        std::cout << "Convert " << s << " to " << num << " successfully!\n";
    else
        std::cout << "Cannot convert " << s << " to number\n";
    // Convert 123 to 123 successfully!

    s   = "abc123";
    num = strtol(s.c_str(), &pEnd, 10);

    if(*pEnd == '\0')
        std::cout << "Convert " << s << " to " << num << " successfully!\n";
    else
        std::cout << "Cannot convert " << s << " to number\n";
    // Cannot convert abc123 to number

    return 0;
}
