#include <iostream>
#include <vector>
#include <numeric> //accumulate

//https://stackoverflow.com/questions/46691506/summation-of-vector-containing-long-long-int-using-accumulation

int main()
{
    std::vector<int> v = {1, 2, 3};

    std::cout << accumulate(v.begin(), v.end(), 0) << std::endl; //6

    v = {1, 2147483647};
    //std::cout << accumulate(v.begin(), v.end(), 0) << std::endl; //-2147483648
    std::cout << accumulate(v.begin(), v.end(), 0L) << std::endl; //2147483648

    return 0;
}
