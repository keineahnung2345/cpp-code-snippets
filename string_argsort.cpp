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
    vector<string> v = {"happy", "ABC", "f", "DE", "a", "harry"};
    vector<size_t> ixs = sort_indexes(v);
    
    //happy ABC f DE a harry 
    for(string e : v){
        cout << e << " ";
    }
    cout << endl;
    
    /**
     * ABC, original 1 th
    DE, original 3 th
    a, original 4 th
    f, original 2 th
    happy, original 0 th
    harry, original 5 th
    **/
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[ixs[i]] << ", original " << ixs[i] << " th" << endl;
    }
    return 0;
}
