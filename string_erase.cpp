#include <string>
#include <iostream>

//https://www.geeksforgeeks.org/stdstringerase-in-cpp/

int main(){
    std::string s = "hello world";
    s.erase(5, 1);
    std::cout << s << std::endl;
    s.erase(0, 5);
    std::cout << s << std::endl;
    /*
    helloworld
    world
    */
    return 0;
}
