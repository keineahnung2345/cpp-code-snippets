#include <iostream>
#include <tuple>

using namespace std;

//http://www.cplusplus.com/reference/tuple/get/

typedef tuple<int, char, bool> ticb;

int main()
{
    ticb tp = {10, 'a', true};
    
    cout << get<0>(tp) << ", " << get<1>(tp) << ", " << get<2>(tp) << endl;
    
    return 0;
}

