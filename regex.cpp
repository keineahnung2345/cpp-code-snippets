#include <iostream>
#include <string>
#include <regex>

//http://www.cplusplus.com/reference/regex/regex_match/

int main(){
    std::string mystr = "hello, good bye and hello";
    std::regex pattern("(hello)(.*)");
    if(std::regex_match(mystr, pattern)){
        std::cout << mystr << " matches the pattern" << std::endl;
    }
    return 0;
}
