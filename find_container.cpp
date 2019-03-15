#include <iostream>
#include <vector>
#include <algorithm> //find
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << *find(v.begin(), v.end(), 5);

    return 0;
}
