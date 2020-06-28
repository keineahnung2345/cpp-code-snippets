#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//https://stackoverflow.com/questions/19529444/cannot-use-stdiota-with-stdset

int main() {
    set<int> myset;
    int n = 10;
    int cur = 1;
    generate_n(inserter(myset, myset.end()), n, 
    [&cur]{ 
        return cur++; 
    });
    
    for(auto it = myset.begin(); it != myset.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}

//1 2 3 4 5 6 7 8 9 10 
