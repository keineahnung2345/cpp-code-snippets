#include <iostream>
#include <vector>
#include <numeric> //iota

using namespace std;

int main()
{
    vector<int> v(10);
    //just like python's range(0, n)
    iota(v.begin(), v.end(), 0); 
    for(int e : v){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
