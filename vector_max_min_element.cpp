#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> myvec;
    for (int i = 0; i < 10; i++)
        myvec.push_back(i);
        
    cout << *std::max_element(myvec.begin(), myvec.end()) << endl;
    cout << *std::min_element(myvec.begin(), myvec.end()) << endl;
    
    return 0;
}
