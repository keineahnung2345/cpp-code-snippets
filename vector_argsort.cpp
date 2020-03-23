#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort
#include <iterator>     // std::ostream_iterator

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
    
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    cout << "nth smallest element is current at what position?" << endl;
    vector<size_t> ixs = sort_indexes(v);
    copy(ixs.begin(), ixs.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    cout << "The element should be put into ?th position:" << endl;
    vector<size_t> putIxs(v.size());
    for(int i = 0; i < v.size(); i++){
        int ix = ixs[i];
        putIxs[ix] = i;
    }
    copy(putIxs.begin(), putIxs.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

/*
5 2 8 0 1 9 
nth smallest element is current at what position?
3 4 1 0 2 5 
The element should be put into ?th position:
3 2 4 0 1 5
*/
