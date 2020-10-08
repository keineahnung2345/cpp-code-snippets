#include <iostream>
#include <climits> //INT_MAX
#include <cfloat> //FLT_MAX, DBL_MAX
#include <limits> //numeric_limits

//http://www.cplusplus.com/reference/climits/
//https://en.cppreference.com/w/cpp/types/numeric_limits

int main(){
    //C-style
    std::cout << INT_MAX << " " << INT_MIN << std::endl; //2147483647 -2147483648 
    std::cout << LLONG_MAX << " " << LLONG_MIN << std::endl; //9223372036854775807 -9223372036854775808
    std::cout << FLT_MAX << " " << FLT_MIN << std::endl; //3.40282e+38 1.17549e-38
    std::cout << DBL_MAX << " " << DBL_MIN << std::endl; //1.79769e+308 2.22507e-308
    //C++-style
    std::cout << std::numeric_limits<float>::max() << " " << std::numeric_limits<float>::min() << " " << std::numeric_limits<float>::lowest() << std::endl;
    std::cout << std::numeric_limits<double>::max() << " " << std::numeric_limits<double>::min() << " " << std::numeric_limits<double>::lowest() << std::endl;
    return 0;
}

/*
2147483647 -2147483648
-9223372036854775808 9223372036854775807
3.40282e+38 1.17549e-38
1.79769e+308 2.22507e-308
3.40282e+38 1.17549e-38 -3.40282e+38
1.79769e+308 2.22507e-308 -1.79769e+308
*/
