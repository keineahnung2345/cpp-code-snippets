#include <iostream>
#include <string>

void replace_all(std::string& str, const std::string& toReplace, const std::string& newText) {
    size_t pos = 0;
    while ((pos = str.find(toReplace, pos)) != std::string::npos) {
        //the 3rd argument means toReplace is replaced with how many newText
        str.replace(pos, toReplace.size(), newText);
        //must need this if newText contains toReplace!
        pos += newText.size();
    }
}

int main() {
    std::string s = "Bob hit a ball, the hit ball flew far after it was hit.";
    std::cout << "old string: " << s << std::endl;

    std::string toReplace("hit");
    std::string newText("shit");

    size_t pos = s.find(toReplace);
    //replace the first occurence
    //NOTE THAT C++ std::string replace is IN-PLACE!!!
    s.replace(pos, toReplace.length(), newText);
    std::cout << "replace one: " << s << std::endl;

    replace_all(s, toReplace, newText);
    std::cout << "replace all: " << s << std::endl;
    
    std::cout << "=====demo of 3rd arg of std::string::replace=====" << std::endl;
    s = "hello, hello, hello";
    std::cout << "old string: " << s << std::endl;
    
    char cToReplace = 'e';
    char cNewText = 'a';
    pos = 0;
    while((pos = s.find(cToReplace, pos)) != std::string::npos){
        s.replace(pos, 1, 3, cNewText);
    }
    std::cout << "replace all: " << s << std::endl;
    return 0;
}

/**
old string: Bob hit a ball, the hit ball flew far after it was hit.
replace one: Bob shit a ball, the hit ball flew far after it was hit.
replace all: Bob sshit a ball, the shit ball flew far after it was shit.
=====demo of 3rd arg of std::string::replace=====
old string: hello, hello, hello
replace all: haaallo, haaallo, haaallo
**/
