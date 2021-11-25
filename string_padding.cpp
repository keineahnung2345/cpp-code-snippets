#include <iostream>
#include <string>

//https://stackoverflow.com/questions/667183/padding-stl-strings-in-c

int main() {
    int         len   = 10;
    std::string mystr = "hello";
    std::string padded(len - mystr.size(), ' ');
    mystr = padded + mystr;
    std::cout << mystr << std::endl;
    return 0;
}

//     hello
