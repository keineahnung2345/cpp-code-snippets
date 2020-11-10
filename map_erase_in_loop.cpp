#include <iostream>
#include <map>

using namespace std;

//https://stackoverflow.com/a/39719450/10651567

int main()
{
    map<int, char> mymap = {
        {1, 'a'},
        {2, 'b'},
        {3, 'c'},
        {4, 'd'},
        {5, 'e'},
        {6, 'f'},
        {7, 'g'},
        {8, 'h'},
        {9, 'i'},
        {10, 'j'}
    };
    
    for (auto it = mymap.cbegin(), next_it = it; it != mymap.cend(); it = next_it){
        ++next_it;
        if (it->first & 1){
            mymap.erase(it);
        }
    }
    
    for(auto it = mymap.begin(); it != mymap.end(); ++it){
        cout << it->first << ", " << it->second << endl;
    }

    return 0;
}
