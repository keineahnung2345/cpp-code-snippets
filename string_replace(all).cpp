#include <iostream>
#include <string>

int main() {
    std::string s = "Bob hit a ball, the hit ball flew far after it was hit.";
    std::cout << "old string: " << s << std::endl;

    std::string toReplace("hit");
    std::string newText("split");

    size_t pos = s.find(toReplace);
    //replace the first occurence
    //NOTE THAT C++ std::string replace is IN-PLACE!!!
    s.replace(pos, toReplace.length(), newText);
    std::cout << "replace one: " << s << std::endl;

    //start search from last end to speed up
    pos = 0;
    while((pos = s.find(toReplace, pos)) != std::string::npos){
        s.replace(pos, toReplace.length(), newText);
    }
    std::cout << "replace all: " << s << std::endl;
    return 0;
}

/*
old string: Bob hit a ball, the hit ball flew far after it was hit.
replace one: Bob split a ball, the hit ball flew far after it was hit.
replace all: Bob split a ball, the split ball flew far after it was split.
*/
