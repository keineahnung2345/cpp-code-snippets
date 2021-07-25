#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/37022167/copy-null-terminated-char-array-to-stdstring-respecting-buffer-length

int main()
{
    const char arr[100] = "hello world"; 
    const vector<char> vc(arr, arr+sizeof(arr));
    
    str = string(vc.begin(), vc.end());
    cout << "last char: " << str.back() << endl;
    
    vector<char>::const_iterator it = find(vc.begin(), vc.end(), '\0');
    string str(vc.begin(), it);
    cout << "last char: " << str.back() << endl;
    return 0;
}

/**
last char: d
last char: 
**/
