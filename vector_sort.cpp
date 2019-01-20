#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {3,6,2,8,1,9};
    
    sort(v.begin(), v.end());
    
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
