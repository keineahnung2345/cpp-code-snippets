#include <iostream>
#include <string>

using namespace std;

//https://stackoverflow.com/questions/23936246/error-invalid-operands-of-types-const-char-35-and-const-char-2-to-binar

int main() {
    const char* c1 = "hello";
    const char* c2 = ", goodbye";
    
    //error: invalid operands of types ‘const char*’ and ‘const char*’ to binary ‘operator+’
    //cout << c1 + c2 << endl;
    
    //hello, goodbye
    cout << string(c1) + c2 << endl;
    return 0;
}
