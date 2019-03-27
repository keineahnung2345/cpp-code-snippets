#include <iostream>

using namespace std;

int main()
{
    string s = "hello world";
    for(string::reverse_iterator rit = s.rbegin(); rit!=s.rend(); rit++){
        cout << *rit;
    }
    cout << endl;
    return 0;
}
