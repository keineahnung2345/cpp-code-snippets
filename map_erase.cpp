#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    map<char, int>::iterator it;
    
    m['a'] = 3;
    m['b'] = 5;
    m['c'] = 7;
    
    cout << "original map..." << endl;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    
    //map::erase method 1
	cout << "erase a..." << endl;
    it = m.find('a');
    
    if(it != m.end()){
        m.erase(it);
    }
    
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    
    //map::erase method 2
	cout << "continue to erase b..." << endl;
    m.erase('b');
    
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}

/*
original map...
a 3
b 5
c 7
erase a...
b 5
c 7
continue to erase b...
c 7
*/
