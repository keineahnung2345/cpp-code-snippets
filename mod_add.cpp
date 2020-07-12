#include <iostream>
#include <vector>
#include <numeric> //accumulate
#include <climits> //INT_MAX
 
using namespace std;

int main() {
    int MOD = 1e9+7;
    
    vector<int> myvec = {INT_MAX-1, INT_MAX-2, INT_MAX, INT_MAX-100};
    
    cout << "wrong result(overflow): " << accumulate(myvec.begin(), myvec.end(), 0) << endl;
    
    cout << "correct result: " << accumulate(myvec.begin(), myvec.end(), 0, 
        [&MOD](const int& a, const int& b){
            return (a%MOD+b%MOD)%MOD;
        }) << endl;
    
    return 0;
}

/*
wrong result(overflow): -107
correct result: 589934429
*/
