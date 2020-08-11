#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/22710331/performing-set-difference-on-unordered-sets
//https://stackoverflow.com/questions/896155/tr1unordered-set-union-and-intersection

int main() {
    unordered_set<int> us1 = {1,2,3};
    unordered_set<int> us2 = {2,3,4};
    unordered_set<int> us_union, us_diff;
    
    cout << "us1 | us2: " << endl;
    us_union = us1;
    copy(us2.begin(), us2.end(), 
         inserter(us_union, us_union.end()));
    for(const int& e : us_union){
        cout << e << " ";
    }
    cout << endl;
    
    cout << "us1 - us2: " << endl;
    copy_if(us1.begin(), us1.end(), 
         inserter(us_diff, us_diff.begin()),
        [&us2] (int needle) { return us2.find(needle) == us2.end(); });
    for(const int& e : us_diff){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}
