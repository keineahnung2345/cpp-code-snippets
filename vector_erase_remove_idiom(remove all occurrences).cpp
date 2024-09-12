#include <algorithm>  //remove
#include <iostream>
#include <vector>

using namespace std;

// https://en.cppreference.com/w/cpp/algorithm/remove
// https://stackoverflow.com/questions/347441/erasing-elements-from-a-vector
// https://stackoverflow.com/questions/34624223/how-to-erase-elements-from-a-vector-based-on-a-specific-condition-in-c11

int main() {
    vector<char> v = { 'a', 'b', 'c', 'a', 'd', 'b' };

    vector<char> v_wo_b = v;
    // erase-remove idiom
    v_wo_b.erase(remove(v_wo_b.begin(), v_wo_b.end(), 'b'), v_wo_b.end());

    for(auto e : v_wo_b) {
        cout << e << " ";
    }
    cout << endl;
    // a c a d

    vector<char> v_larger_than_b = v;
    // erase-remove idiom
    v_larger_than_b.erase(
        remove_if(v_larger_than_b.begin(), v_larger_than_b.end(),
                  [](char c) { return c <= 'b'; }),
        v_larger_than_b.end());

    for(auto e : v_larger_than_b) {
        cout << e << " ";
    }
    cout << endl;
    // c d

    return 0;
}
