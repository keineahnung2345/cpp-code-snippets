#include <iostream>
#include <set>

using namespace std;

//https://stackoverflow.com/questions/7089494/merge-multiple-sets-elements-in-a-single-set

int main() {
    set<int> s1 = {1,2,3};
    set<int> s2 = {4,5,6};
    
    s1.insert(s2.begin(), s2.end());
    
    for(const int& e : s1){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//1 2 3 4 5 6 
