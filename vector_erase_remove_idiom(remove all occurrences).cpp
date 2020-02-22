#include <iostream>
#include <vector>
#include <algorithm> //remove

using namespace std;


//https://en.cppreference.com/w/cpp/algorithm/remove
//https://stackoverflow.com/questions/347441/erasing-elements-from-a-vector

int main()
{
    vector<char> v = {'a', 'b', 'c', 'a', 'd', 'b'};
    
    //erase-remove idiom
    v.erase(remove(v.begin(), v.end(), 'b'), v.end());
    
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//a c a d
