#include <vector>
#include <algorithm> //copy, copy_n
#include <iterator> //advance
#include <iostream>
using namespace std;

//https://stackoverflow.com/questions/13760174/replacing-subvector-in-a-vector

int main() {
    vector<int> vec1 = {1,2,3,4};
    vector<int> vec2 = {5,6,7,8,9,10};
    
    int n = 1;
    vector<int>::iterator dst = vec2.begin();
    advance(dst, n);
    
    //Method 1: copy
    copy(vec1.begin(), vec1.begin()+3, dst);
    
    //Method 2: copy_n
    copy_n(begin(vec1), 3, dst);
    
    for(int e : vec2){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//5 1 2 3 9 10 
