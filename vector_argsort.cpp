#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort

using namespace std;

//note that the argument is passed by reference
//so v will be modified!
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
    vector<size_t> ixs = sort_indexes(v);
    
    //5 2 8 0 1 9 
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    
    /**
     * index: 3, value: 0
    index: 4, value: 1
    index: 1, value: 2
    index: 0, value: 5
    index: 2, value: 8
    index: 5, value: 9
    **/
    for (auto i: ixs) {
        cout << "index: " << i << ", value: " << v[i] << endl;
    }

    return 0;
}
