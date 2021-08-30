#include <iostream>
#include <string>
#include <vector>
#include <type_traits> //std::is_scalar

//https://www.geeksforgeeks.org/is_scalar-template-in-c/

int main() {
    std::cout << "std::string is a scalar? " << std::boolalpha << std::is_scalar<std::string>::value << std::endl;
    std::cout << "int is a scalar? " << std::boolalpha << std::is_scalar<int>::value << std::endl;
    std::cout << "std::vector<int> is a scalar? " << std::boolalpha << std::is_scalar<std::vector<int>>::value << std::endl;
    return 0;
}

/**
std::string is a scalar? false
int is a scalar? true
std::vector<int> is a scalar? false
**/
