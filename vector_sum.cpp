#include <iostream>
#include <vector>
#include <numeric> //accumulate

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    
    cout << accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
}
