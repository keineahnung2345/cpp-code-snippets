#include <iostream>
#include <iterator>
#include <string>

//https://stackoverflow.com/questions/15578178/how-to-end-iteration-through-a-c-stdset-one-element-early

using namespace std;

int main() {
    string str("hello world");
    
    cout << *prev(str.end()) << endl; //d
    cout << *(str.end()-1) << endl; //d
    
    return 0;
}
