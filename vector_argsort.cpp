#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort

using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

int main()
{
    vector<int> v = {5,2,8,0,1,9};
    
    for (auto i: sort_indexes(v)) {
        cout << "index: " << i << ", value: " << v[i] << endl;
    }

    return 0;
}
