#include <iostream>
#include <set>
#include <unordered_set>
#include <iterator>     // std::advance

using namespace std;

int main()
{
    set<int> myset = {1,5,8,2,0,3};
    unordered_set<int> myuset = {1,5,8,2,0,3};
    
    set<int>::iterator itset = myset.begin();
    advance(itset, rand()%myset.size());
    cout << (*itset) << endl;
    
    unordered_set<int>::iterator ituset = myuset.begin();
    advance(ituset, rand()%myuset.size());
    cout << (*ituset) << endl;

    return 0;
}

/*
1
8
*/
