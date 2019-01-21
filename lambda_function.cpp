#include <iostream>
#include <vector>
#include <algorithm> //for_each

using namespace std;

int main()
{
    std::vector<int> some_list;
    int total = 0;
    for (int i=0;i<5;i++) some_list.push_back(i);
    
    //C++ 11 lambda function: [capture](parameters)->return-type{body}
    std::for_each(begin(some_list), end(some_list), [&total](int x) {
        total += x;
    });
    cout << total << endl;
    return 0;
}
