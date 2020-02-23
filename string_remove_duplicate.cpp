#include <string>
#include <iostream>

//https://stackoverflow.com/questions/8362094/replace-multiple-spaces-with-one-space-in-a-string

int main(){
    std::string mystr = "hello    world   good        bye";
    char dup = ' '; //the duplicate character to be removed
    std::cout << mystr << std::endl;
    mystr.erase(
        std::unique(mystr.begin(), mystr.end(),
            [dup](const char& lhs, const char& rhs){return lhs == dup && (lhs == rhs);}
        ),
        mystr.end()
    );
    std::cout << mystr << std::endl;
    return 0;
}

/*
hello    world   good        bye
hello world good bye
*/
