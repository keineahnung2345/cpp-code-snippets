#include <iostream>
#include <vector>
#include <set>
#include <algorithm> //transform

using namespace std;

//https://stackoverflow.com/questions/908272/stdback-inserter-for-a-stdset

int main() {
    vector<int> myvec = {1,2,3};
    vector<int> myemptyvec;
    set<int> myset = {1,2,3}, tmp;
    
    //target vector's size is the same as source vector's
    transform(myvec.begin(), myvec.end(), myvec.begin(), [](int& x){return x+1;});
    
    //target vector is empty, need to use "back_inserter"
    transform(myvec.begin(), myvec.end(), back_inserter(myemptyvec), [](int& x){return x+1;});
    
    //cannot add "&" in lambda function!
    transform(myset.begin(), myset.end(), inserter(tmp, tmp.end()), [](int x){return x+1;});
    swap(myset, tmp);
    
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
    
    for(int e : myemptyvec){
        cout << e << " ";
    }
    cout << endl;
    
    for(int e : myset){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//2 3 4 
//3 4 5 
//2 3 4 
