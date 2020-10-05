#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main()
{
    set<int> myset = {1,2,4,8,16};
    
    vector<int> xs = {0,2,5,17};
    
    //lower_bound: >=
    //upper_bound: >
    for(int& x : xs){
        auto it_low = myset.lower_bound(x);
        auto it_up = myset.upper_bound(x);
        
        cout << x << "'s lower bound: " << ((it_low == myset.end()) ? "null" : to_string(*it_low)) << 
        ", upper bound: " << ((it_up == myset.end()) ? "null" : to_string(*it_up)) << endl;
    }
    
    return 0;
}
