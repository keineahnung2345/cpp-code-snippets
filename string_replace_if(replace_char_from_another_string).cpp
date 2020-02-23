#include <iostream>
#include <string>

//http://www.cplusplus.com/reference/algorithm/replace_if/

int main(){
    std::string mystr = "Hello! How is he? He's fine, he's good.;";
    std::string toRemove = "!?',;.";
    std::replace_if(mystr.begin(), mystr.end(),
        [toRemove](char c) { return toRemove.find(c) != std::string::npos;}, ' ');
    std::cout << mystr << std::endl;
    return 0;
}

/*
Hello  How is he  He s fine  he s good
*/
