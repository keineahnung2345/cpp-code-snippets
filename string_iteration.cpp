#include <iostream>

using namespace std;

int main()
{
    string s = "abc";
    
    //https://stackoverflow.com/questions/14668326/iterate-through-string-char-by-char
    for(auto c : s){
        cout << c << " ";
    }
    cout << endl;
    
    for(char c : s){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
