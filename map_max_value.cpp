#include <iostream>
#include <map>
#include <utility> //pair
#include <algorithm> //max_element

using namespace std;

//https://stackoverflow.com/questions/9370945/c-help-finding-the-max-value-in-a-map

int main()
{
    map<int, int> mymap;
    mymap[10] = 3;
    mymap[20] = 5;
    mymap[30] = 4;
    mymap[40] = 1;
    mymap[50] = 2;
    
    map<int, int>::iterator p = max_element(mymap.begin(), mymap.end(), [] (const pair<int, int> & p1, const pair<int, int> & p2) {
        return p1.second < p2.second;
    });
    
    cout << p->first << " " << p->second << endl;
    
    return 0;
}
