#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, char> mymap = {{1,'a'}, {2,'b'}, {3,'c'}, 
    {4,'d'}, {5,'e'}, {6,'f'}, {7,'g'}, {8,'h'}, {9, 'i'}, {10, 'j'}};
    
    auto it = mymap.begin();

    //std::advance change its argument directly and return void
    advance(it, 4);
    cout << it->first << ", " << it->second << endl; //5, e

    advance(it, -2);
    cout << it->first << ", " << it->second << endl; //3, c
    
    //std::next doesn't change its argument but make a copy
    auto it2 = next(it, 4);
    cout << it2->first << ", " << it2->second << endl; //7, g
    
    //std::prev doesn't change its argument but make a copy
    auto it3 = prev(it2, 3);
    cout << it3->first << ", " << it3->second << endl; //4, d
    
    return 0;
}
