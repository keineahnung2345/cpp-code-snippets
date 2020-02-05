#include <iostream>
#include <limits>       // std::numeric_limits

//http://www.cplusplus.com/reference/limits/numeric_limits/

int main(){
    std::cout << "max, min, lowest for 5 different data types: " << std::endl;
    std::cout << "\nint: " << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::numeric_limits<int>::lowest() << std::endl;
    
    std::cout << "\nunsigned int: " << std::endl;
    std::cout << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::lowest() << std::endl;
    
    std::cout << "\nfloat: " << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<float>::lowest() << std::endl;
    
    std::cout << "\ndouble: " << std::endl;
    std::cout << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::numeric_limits<double>::min() << std::endl;
    std::cout << std::numeric_limits<double>::lowest() << std::endl;
    
    std::cout << "\nlong double: " << std::endl;
    std::cout << std::numeric_limits<long double>::max() << std::endl;
    std::cout << std::numeric_limits<long double>::min() << std::endl;
    std::cout << std::numeric_limits<long double>::lowest() << std::endl;
    
    return 0;
}   

/*
max, min, lowest for 5 different data types:

int:
2147483647
-2147483648
-2147483648

unsigned int:
4294967295
0
0

float:
3.40282e+38
1.17549e-38
-3.40282e+38

double:
1.79769e+308
2.22507e-308
-1.79769e+308

long double:
1.18973e+4932
3.3621e-4932
-1.18973e+4932
*/
