#include <iostream>
#include <string>

using namespace std;

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

bool is_number(std::string s){
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
};

int main() {
    cout << is_number("123") << endl;    //1
    cout << is_number("abc") << endl;    //0
    cout << is_number("123abc") << endl; //0
    return 0;
}
