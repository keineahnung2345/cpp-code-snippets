#include <iostream>
#include <vector>
#include <algorithm> //find

using namespace std;

//https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

int main() {
    vector<int> v = {1,2,3,2,3,2,2};
	
    for(int e : v) cout << e << " ";
    cout << endl;
	
    //remove the first occurrence of 2
    auto it = find(v.begin(), v.end(), 2);
    if(it != v.end()){
        v.erase(it);
    }
	
    for(int e : v) cout << e << " ";
    cout << endl;
	
    return 0;
}

/*
1 2 3 2 3 2 2 
1 3 2 3 2 2 
*/
