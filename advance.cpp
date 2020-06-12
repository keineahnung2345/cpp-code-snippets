#include <iostream>
#include <set>
#include <iterator> //advance

using namespace std;

//http://www.cplusplus.com/reference/iterator/advance/

int main() {
    // your code goes here
    set<int> myset = {1,2,3,4,5};
    set<int>::iterator it = myset.begin(); 
    advance(it, 3);
    cout << *it << endl;
    return 0;
}

//4
