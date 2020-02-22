#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

//https://stackoverflow.com/questions/9025084/sorting-a-vector-in-descending-order

int main()
{
    std::vector<int> v = {3,6,2,8,1,9};

    std::sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //1 2 3 6 8 9

    std::sort(v.begin(), v.end(), std::greater<int>());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //9 8 6 3 2 1

    return 0;
}
