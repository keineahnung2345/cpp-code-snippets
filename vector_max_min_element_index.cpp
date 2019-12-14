#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/2953491/finding-the-position-of-the-max-element

int main() {
    vector<int> myvec = {3,4,1,7,9,2,5};

    cout << "max's index: " << std::distance(myvec.begin(), std::max_element(myvec.begin(), myvec.end())) << ", value: " << *std::max_element(myvec.begin(), myvec.end()) << endl;
    cout << "min's index: " << std::distance(myvec.begin(), std::min_element(myvec.begin(), myvec.end())) << ", value: " << *std::min_element(myvec.begin(), myvec.end()) << endl;

    /*
    max's index: 4, value: 9
    min's index: 2, value: 1
    */

    return 0;
}
