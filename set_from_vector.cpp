#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 3, 5, 7, 7, 7};
    
    set<int> myset(v.begin(), v.end());
    
    for(set<int>::iterator it = myset.begin(); it!=myset.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
