#include <iostream>
#include <algorithm> //random_shuffle
#include <vector>
 
using namespace std;
 
int main() {
    vector<int> myvec = {1,2,3,4,5,6};
 
    random_shuffle(myvec.begin(), myvec.end());
 
    for(int& e : myvec){
        cout << e << " ";
    }
    cout << endl;
 
    return 0;
}

//5 4 2 3 1 6
