#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    
    for(int e : v) cout << e << " ";
    cout << endl;
    
    //remove 8
    v.erase(v.begin()+7);
    
    for(int e : v) cout << e << " ";
    cout << endl;
    
    //remove 4,5
    v.erase(v.begin()+3, v.begin()+5);
    for(int e : v) cout << e << " ";
    cout << endl;
    
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 9 
1 2 3 6 7 9 
*/
