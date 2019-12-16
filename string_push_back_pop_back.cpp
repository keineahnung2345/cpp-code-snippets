#include <string>
#include <iostream>

int main(){
    std::string s = "What?";
    s.pop_back(); //c++11
    s.push_back('!');
    std::cout << s << std::endl; //What!
    return 0;
}
