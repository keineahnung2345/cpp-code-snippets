#include <iostream>
#include <string>
#include <string>

using namespace std;

int main()
{
    string s1 = "hello world";
    string s2 = "hello";
    
    if(s1.find(s2)!=string::npos){
        cout << s1 << " contains " << s2 << endl;
    }
}
