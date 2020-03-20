#include <iostream>
#include <climits> //INT_MAX
#include <cfloat> //FLT_MAX

using namespace std;

//http://www.cplusplus.com/reference/climits/

int main()
{
    
    int a = INT_MAX, b = INT_MIN;
    float c = FLT_MAX, d = FLT_MIN;
    cout << a << " " << b << endl; //2147483647 -2147483648 
    cout << c << " " << d << endl; //3.40282e+38 1.17549e-38
    return 0;
}
