#include <iostream>
#include <map> 

using namespace std; 

/*
in C++:
lower_bound: >=, upper_bound: >
*/

int main() 
{ 
    // initialize container 
    map<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 12, 30 }); 
    mp.insert({ 11, 10 }); 
    mp.insert({ 15, 50 }); 
    mp.insert({ 14, 40 }); 
  
    auto it = mp.upper_bound(9); 
    cout << "The upper bound of key 9 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 11 is present 
    it = mp.upper_bound(11); 
    cout << "The upper bound of key 11 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 13 is not present 
    it = mp.upper_bound(13); 
    cout << "The upper bound of key 13 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 17 is exceeds the maximum key
    it = mp.upper_bound(17); 
    cout << "The upper bound of key 17 is "; 
    if(it == mp.end()){
        cout << "cannot find" << endl;
    }
  
    it = mp.lower_bound(9); 
    cout << "The lower bound of key 9 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 11 is present 
    it = mp.lower_bound(11); 
    cout << "The lower bound of key 11 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 13 is not present 
    it = mp.lower_bound(13); 
    cout << "The lower bound of key 13 is "; 
    cout << (*it).first << " " << (*it).second << endl; 
  
    // when 17 is exceeds the maximum key
    it = mp.lower_bound(17); 
    cout << "The lower bound of key 17 is "; 
    if(it == mp.end()){
        cout << "cannot find" << endl;
    }
    
    return 0; 
} 

/*
The upper bound of key 9 is 11 10
The upper bound of key 11 is 12 30
The upper bound of key 13 is 14 40
The upper bound of key 17 is cannot find
The lower bound of key 9 is 11 10
The lower bound of key 11 is 11 10
The lower bound of key 13 is 14 40
The lower bound of key 17 is cannot find
*/
