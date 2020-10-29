#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<char, int> mymap = {
        {'a', 34},
        {'b', 37},
        {'c', 21}
    };
    
    auto min_it = min_element(mymap.begin(), mymap.end(),
        [](const pair<char, int>& p, const pair<char, int>& q){
            return p.second < q.second;
        });
    
    cout << min_it->first << ", " << min_it->second << endl; //c, 21

    return 0;
}

