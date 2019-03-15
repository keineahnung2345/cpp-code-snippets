#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> v = {'a', 'b', 'c'};
    cout << string(v.begin(),v.end());
    return 0;
}
