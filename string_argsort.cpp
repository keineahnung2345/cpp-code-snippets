#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <numeric> //iota

using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {
  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1].compare(v[i2]) < 0;});

  return idx;
}

int main()
{
    vector<string> v = {"ABC", "DE", "a", "happy", "harry", "f"};
    sort_indexes(v);
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
