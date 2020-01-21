#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/2953491/finding-the-position-of-the-max-element

int main() {
    vector<int> myvec = {3,4,1,7,9,2,5};

    cout << "max's index: " << std::distance(myvec.begin(), std::max_element(myvec.begin(), myvec.end())) << ", value: " << *std::max_element(myvec.begin(), myvec.end()) << endl;
    cout << "min's index: " << std::distance(myvec.begin(), std::min_element(myvec.begin(), myvec.end())) << ", value: " << *std::min_element(myvec.begin(), myvec.end()) << endl;
    // tail is not inclusive, so we need +1 here
    cout << "max among [0:3] , index : " << std::distance(myvec.begin(), std::max_element(myvec.begin(), myvec.begin() + 3 + 1)) << ", value: " << *std::max_element(myvec.begin(), myvec.begin() + 3 + 1) << endl;
    return 0;
}

/*
max's index: 4, value: 9
min's index: 2, value: 1
max among [0:3] , index : 3, value: 7
*/
