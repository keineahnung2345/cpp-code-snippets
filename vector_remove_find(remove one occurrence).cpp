#include <iostream>
#include <vector>
#include <algorithm> //find

using namespace std;

//https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

int main()
{
    vector<char> v = {'a', 'b', 'c', 'a', 'd', 'b'};
    
    vector<char>::iterator position = find(v.begin(), v.end(), 'b');
    if (position != v.end())
        v.erase(position);
    
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}
