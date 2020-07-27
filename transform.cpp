#include <iostream>
#include <vector>
#include <set>
#include <algorithm> //transform

using namespace std;

//https://stackoverflow.com/questions/908272/stdback-inserter-for-a-stdset

int main() {
    vector<int> myvec = {1,2,3};
    set<int> myset = {1,2,3}, tmp;
    
    transform(myvec.begin(), myvec.end(), myvec.begin(), [](int& x){return x+1;});
    //cannot add "&" in lambda function!
    transform(myset.begin(), myset.end(), inserter(tmp, tmp.end()), [](int x){return x+1;});
    swap(myset, tmp);
    
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
    
    for(int e : myset){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}
