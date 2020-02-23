#include <iostream>
#include <string>

//https://stackoverflow.com/questions/20971804/reading-stdstring-remove-all-special-characters-from-a-stdstring

int main(){
    std::string mystr = "Hello! How is he? He's fine, he's good.;";
    std::string toRemove = "!?',;.";
    mystr.erase(std::remove_if(mystr.begin(), mystr.end(),
        [toRemove](char c) { return toRemove.find(c) != std::string::npos;} ),
        mystr.end());
    std::cout << mystr << std::endl;
    return 0;
}

/*
Hello How is he Hes fine hes good
*/
