#include <iostream>
#include <vector>
#include <functional>   // std::greater
#include <algorithm>    // std::sort

int main(){
    std::vector<int> myvec = {0, 5, 2, 8, 12, 9, 3};

    //ascending
    std::sort(myvec.begin(), myvec.end(), std::less<int>());
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //descending
    std::sort(myvec.begin(), myvec.end(), std::greater<int>());
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

/*
0 2 3 5 8 9 12
12 9 8 5 3 2 0
*/
