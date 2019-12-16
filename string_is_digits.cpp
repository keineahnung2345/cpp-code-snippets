#include <iostream>
#include <string>
#include <algorithm>

//https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits

bool is_digits(const std::string &str)
{
    //isdigit: c function
    //https://www.programiz.com/c-programming/library-function/ctype.h/isdigit
    //all_of: http://www.cplusplus.com/reference/algorithm/all_of/
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

int main(){
    std::string s1 = "1234", s2 = "1234.567", s3 = "abc";
    std::cout << s1 << " is digit: " << is_digits(s1) << std::endl;
    std::cout << s2 << " is digit: " << is_digits(s2) << std::endl;
    std::cout << s3 << " is digit: " << is_digits(s3) << std::endl;
    /*
    1234 is digit: 1
    1234.567 is digit: 0
    abc is digit: 0
    */
    return 0;
}
