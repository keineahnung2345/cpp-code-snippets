#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v = {"a", "b", "c"};
    for(auto e : v){
        cout << e << " ";
        v.push_back(e);
        cout << " after "; 
    }
    cout << endl;
    
    for(auto e : v){
        cout << e << " ";
    }
    
    /**
    a  after   after   after                                                                                                                       
    a b c a
    **/
    
    /**
    it seems after pushing an element into v, 
    we cannot iterate it normally anymore!
    **/
    return 0;
}
