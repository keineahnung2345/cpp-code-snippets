#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    m['a'] = 3;
    m['b'] = 5;
    m['c'] = 7;
    
    map<char, int>::iterator it = m.find('a');
    
    if(it != m.end()){
        m.erase(it);
    }
    
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
