#include <iostream>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/201718/concatenating-two-stdvectors

int main() {
    vector<int> v1 {1,2,3,4,5,6};
    vector<int> v2 {7,8,9,10};
    
    v1.insert(v1.end(), v2.begin(), v2.end());
    
    for(auto e : v1){
        cout << e << " ";
    }
    cout << endl;
}
