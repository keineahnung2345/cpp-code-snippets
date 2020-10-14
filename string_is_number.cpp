#include <iostream>
#include <string>

using namespace std;

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

//support positive and negative integer
bool is_number(const std::string& s){
    if(s.empty()) return false;
    if(s.size() > 1 && s[0] == '-' && s.find_first_not_of("0123456789", 1) == std::string::npos) return true;
    return s.find_first_not_of("0123456789") == std::string::npos;
};

int main() {
    cout << is_number("123") << endl;    //1
    cout << is_number("-123") << endl;    //1
    cout << is_number("-123abc") << endl;    //0
    cout << is_number("-") << endl;    //0
    cout << is_number("abc") << endl;    //0
    cout << is_number("123abc") << endl; //0
    return 0;
}
