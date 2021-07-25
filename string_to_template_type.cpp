#include <iostream>
#include <string>
#include <sstream>

//https://stackoverflow.com/questions/19545883/how-to-convert-string-to-template-type

using namespace std;

template<typename T>
void setVar(const std::string& str, T& var) {
    std::stringstream ss(str);
    ss >> var;
}

int main() {
    int i;
    float f;
    
    setVar("123", i);
    setVar("123.456", f);
    
    cout << i << endl;
    cout << f << endl;
    return 0;
}
