#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> counter;
    counter['a'] = 5;
    counter['b'] = 3;
    counter['c'] = 4;
    counter['d'] = 1;
    counter['e'] = 7;
    
    cout << counter.begin()->first << ", " << counter.begin()->second << endl; //a, 5
    cout << counter.rbegin()->first << ", " << counter.rbegin()->second << endl; //e, 7
    return 0;
}

