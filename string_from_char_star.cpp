#include <string>
#include <iostream>

//https://www.geeksforgeeks.org/convert-character-array-to-string-in-c/
//https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring

int main(){
    char a[] = { 'C', 'O', 'D', 'E', '\0'};
    char b[] = "geeksforgeeks";
    char* c = "abc";
    int l = 3;

    std::string s(a);
    std::cout << s << std::endl;
    
    s = b;
    std::cout << s << std::endl;
    
    s.assign(c, l);
    std::cout << s << std::endl;
    return 0;
}

/*
CODE
geeksforgeeks
abc
*/

