#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <numeric> //iota

using namespace std;

//original version's argument is const vector<T>& v
//here remove & so that v won't be modified
template <typename T>
vector<size_t> sort_indexes(const vector<T> v) {
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
    
    for(int i = 0; i < (int)v.size(); i++){
        cout << ixs[i] << " th smallest: " <<  v[i] << endl;
    }
    return 0;
}
