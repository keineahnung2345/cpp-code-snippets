#include <iostream>
#include <map>

using namespace std;

int main() {
    //(start point, end point)
    map<int, int> intervals = {{1,5}, {3,6}, {2,4}, {4, 7}, {5,5}}; 
    
    cout << "finding in ..." << endl;
    for(auto it = intervals.begin(); it != intervals.end(); it++){
        cout << "[" << it->first << ", " << it->second << "] ";
    }
    cout << endl;
    
    int toFind = 3;
    auto it = intervals.lower_bound(toFind);
    if(it == intervals.end()){
        cout << "cannot find interval whose end larger than or equal to " << toFind << endl;
    }else{
        cout << "found an interval whose starting point >= " << toFind << ", whose ending point is " << it->second << endl;
    }
    
    return 0;
}

/*
finding in ...
[1, 5] [2, 4] [3, 6] [4, 7] [5, 5] 
found an interval whose starting point >= 3, whose ending point is 6
*/
