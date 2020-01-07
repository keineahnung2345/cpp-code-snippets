#include <string>
#include <iostream>

//https://www.geeksforgeeks.org/convert-character-array-to-string-in-c/

int main(){
    char a[] = { 'C', 'O', 'D', 'E' };
    char b[] = "geeksforgeeks";

    std::string s(a);
    std::cout << s << std::endl;
    s = b;
    std::cout << s << std::endl;
    return 0;
}
