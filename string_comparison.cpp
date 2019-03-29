#include <iostream>

using namespace std;

int main()
{
    string s = "abc";
    
    cout << (s=="abc") << endl;
    cout << (s=="bac") << endl;
    cout << (s=="d") << endl;
    
    cout << string("hello").compare("world") << endl; //-15
    cout << string("A").compare("Ab") << endl; //-1
    cout << string("AB").compare("CD") << endl; //-2
    cout << string("ABC").compare("ABC") << endl; //0
    cout << string("harry").compare("happy") << endl; //2
    return 0;
}
