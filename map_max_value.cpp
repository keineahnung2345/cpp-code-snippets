#include <iostream>
#include <map>
#include <utility> //pair
#include <algorithm> //max_element

//https://stackoverflow.com/questions/9370945/c-help-finding-the-max-value-in-a-map

int main()
{
    std::map<int, int> mymap;
    mymap[10] = 3;
    mymap[20] = 5;
    mymap[30] = 4;
    mymap[40] = 1;
    mymap[50] = 2;

    std::map<int, int>::iterator p = std::max_element(mymap.begin(), mymap.end(), [] (const std::pair<int, int> & p1, const std::pair<int, int> & p2) {
        return p1.second < p2.second;
    });

    std::cout << p->first << " " << p->second << std::endl;

    return 0;
}

//20 5
