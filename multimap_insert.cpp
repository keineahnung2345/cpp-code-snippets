#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    std::multimap<int, char> mymultimap = {
        {1, 'a'},
        {2, 'b'}
    };
 
    //invalid
    //mymultimap[3] = 'c';
 
    //correct way to add key-value pairs to multimap
    mymultimap.insert(make_pair(3, 'c'));
    mymultimap.insert(make_pair(2, 'e'));
    mymultimap.insert(make_pair(3, 'f'));
 
    for(std::multimap<int,char>::iterator it = mymultimap.begin(); it != mymultimap.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}
