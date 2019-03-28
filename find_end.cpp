#include <iostream>
#include <vector>
#include <algorithm> //find_end

using namespace std;

int main()
{
    vector<int> v = {1, 6, 2, 3, 4, 5, 6, 2};
    vector<int> tofind = {6};
    
    vector<int>::iterator it = find_end(v.begin(), v.end(), tofind.begin(), tofind.end());
    
    cout << "last 6 is the " << it - v.begin() << " th value in v" << endl;;
    return 0;
}
