#include <iostream>

using namespace std;

int main()
{
    string s = "abcdef";
    
    cout << s.substr(3,2) << " " << s.substr(3,2).size()  << endl; //de 2
    cout << s.substr(3,4) << " " << s.substr(3,4).size() << endl; //def 3

    return 0;
}
