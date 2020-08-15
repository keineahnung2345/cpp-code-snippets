#include <iostream>
#include <string>
#include <regex>

//http://www.cplusplus.com/reference/regex/regex_match/
//http://www.cplusplus.com/reference/regex/regex_replace/

int main(){
    std::string mystr = "hello, good bye and hello";
    std::regex pattern("(hello)(.*)");
    if(std::regex_match(mystr, pattern)){
        std::cout << mystr << " matches the pattern" << std::endl;
    }
    
    mystr = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    std::cout << "before: " << mystr << std::endl;
    pattern = std::regex("<!\\[CDATA\\[.*?\\]\\]>");
    mystr = regex_replace(mystr, pattern, "c");
    std::cout << "after: " << mystr << std::endl;
    return 0;
}

/*
hello, good bye and hello matches the pattern
before: <DIV>This is the first line <![CDATA[<div>]]></DIV>
after: <DIV>This is the first line c</DIV>
*/
