#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

int main(){
    std::string sd = "123.456789123";
    std::cout << std::stod(sd) << std::endl; //123.457
    std::cout << std::stold(sd) << std::endl; //123.457
    std::stringstream ss;
    ss << std::fixed << std::setprecision(10) << sd;
    std::string str = ss.str();
    std::cout << str << std::endl; //123.456789123
    return 0;
}
