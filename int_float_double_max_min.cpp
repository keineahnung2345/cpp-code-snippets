#include <iostream>
#include <climits> //INT_MAX
#include <cfloat> //FLT_MAX, DBL_MAX

using namespace std;

//http://www.cplusplus.com/reference/climits/

int main(){
    cout << INT_MAX << " " << INT_MIN << endl; //2147483647 -2147483648 
    cout << FLT_MAX << " " << FLT_MIN << endl; //3.40282e+38 1.17549e-38
    cout << DBL_MAX << " " << DBL_MIN << endl; //1.79769e+308 2.22507e-308
    return 0;
}
