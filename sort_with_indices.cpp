#include <algorithm>  // std::sort, std::stable_sort
#include <iostream>
#include <numeric>  // std::iota
#include <vector>

using namespace std;

// https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes

template <typename T>
vector<size_t> sort_indexes(const vector<T>& v) {
    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}

int main() {
    vector<int> v = { 4, 6, 7, 1, 3, 2, 9, 8, 7, 0, 5 };
    for(auto i : sort_indexes(v)) {
        cout << i << "th element: " << v[i] << endl;
    }
    return 0;
}

/*
9th element: 0
3th element: 1
5th element: 2
4th element: 3
0th element: 4
10th element: 5
1th element: 6
2th element: 7
8th element: 7
7th element: 8
6th element: 9
*/
