#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/4461446/stl-way-to-add-a-constant-value-to-a-stdvector

int main() {
    int addend = 5;
    vector<int> myvec = {1,2,3};
    
    //Method 1:
    for_each(myvec.begin(), myvec.end(), [&addend](int& e) { e+=addend;});
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
    
    //Method 2:
    //The function allows for the destination range to be the same as one of the input ranges to make transformations in place.
    transform(myvec.begin(), myvec.end(), myvec.begin(), [&addend](int e){return e+addend;});
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//6 7 8 
//11 12 13 
