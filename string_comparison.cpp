#include <iostream>

using namespace std;

int main()
{
    string s = "abc";
    
    cout << (s=="abc") << endl; //1
    cout << (s=="bac") << endl; //0
    cout << (s=="d") << endl; //0
    
    cout << string("hello").compare("world") << endl; //-15
    cout << string("A").compare("Ab") << endl; //-1
    cout << string("AB").compare("CD") << endl; //-2
    cout << string("ABC").compare("ABC") << endl; //0
    cout << string("harry").compare("happy") << endl; //2
    return 0;
}
