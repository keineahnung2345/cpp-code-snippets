#include <iostream>
#include <set>
#include <vector>
#include <algorithm> //set_symmetric_difference

using namespace std;


int main()
{
    set<char> s1, s2;
    vector<char> v(10);
    vector<char>::iterator v_it;
    
    s1.insert('a');
    s1.insert('b');
    s1.insert('c');
    s1.insert('d');
    
    s2.insert('b');
    s2.insert('c');
    s2.insert('e');
    
    cout << "intersection:" << endl;
    v_it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    v.resize(v_it-v.begin());
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    
    
    cout << "symmetric difference:" << endl;
    v.resize(10);
    v_it = set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    v.resize(v_it-v.begin());
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

