#include <iostream>
#include <string>
#include <string>

using namespace std;

int main()
{
    string s1 = "ABCABABC";
    string s2 = "ABC";
    
    size_t found = s1.find(s2);
    if(found != string::npos){
        cout << s1 << " contains " << s2 << ", starts from " << found << endl;
    }
    
    found = s1.find(s2, found+1);
    if(found != string::npos){
        cout << s1 << " still contains " << s2 << ", starts from " << found << endl;
    }
}

/*
ABCABABC contains ABC, starts from 0
ABCABABC still contains ABC, starts from 5
*/
