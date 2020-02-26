#include <iostream>
#include <string>

int main(){
    std::string s = "abcdef";
    std::cout << "original: " << s << std::endl;

    //in-place, return void
    std::reverse(s.begin(), s.end());
    std::cout << "reverse(in-place): " << s << std::endl;

    //create a new string
    std::string s2 = std::string(s.rbegin(), s.rend());
    std::cout << "reverse again, create a new string: " << s2 << std::endl;

    return 0;
}

/*
original: abcdef
reverse(in-place): fedcba
reverse again, create a new string: abcdef
*/
