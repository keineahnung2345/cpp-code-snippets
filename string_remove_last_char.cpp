#include <iostream>
#include <string>

int main() {
    std::string str = "hello world";
    std::cout << str << "->";
    str.pop_back();
    std::cout << str << std::endl;
    return 0;
}

//hello world->hello worl
