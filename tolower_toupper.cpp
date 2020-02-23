#include <iostream>
#include <limits>

//https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
//https://en.cppreference.com/w/cpp/string/byte/tolower

int main() {
    std::cout << std::tolower('A') << " " << (char)std::tolower('A') << std::endl; //97 a
    std::cout << std::toupper('a') << " " << (char)std::toupper('a') << std::endl; //65 A
    std::string s = "Hello WORLD";
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::tolower(c);});
    std::cout << s << std::endl;
    return 0;
}

/*
97 a
65 A
hello world
*/
