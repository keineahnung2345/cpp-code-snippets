#include <iostream>
#include <string>

using namespace std;

int main() {
    int a;
    int n = 2;
    while(cin >> a){
        cout << "Read number: " << a << endl;
        if(--n == 0) break;
    }
	
    string str;
    while(getline(cin, str)){
        cout << str << endl;
    }
    return 0;
}

/*
Input:
1 2
hello goodbye
hey yolo
checkout here
*/

/*
Output:
Read number: 1
Read number: 2

hello goodbye
hey yolo
checkout here

*/
