#include <iostream>

using namespace std;

int main()
{
    string s = "abcdef";

    cout << s.substr(3,2) << " " << s.substr(3,2).size()  << endl; //de 2
    //If 2nd argument len is greater than size of string, then returned sub-string is [pos, size()).
    cout << s.substr(3,4) << " " << s.substr(3,4).size() << endl; //def 3
    //without 2nd argument: to the end
    cout << s.substr(3) << " " << s.substr(3).size() << endl; //def 3

    return 0;
}
