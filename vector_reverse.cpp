#include <algorithm> // std::reverse
#include <iostream>
#include <vector>

//http://www.cplusplus.com/reference/algorithm/reverse/

int main(){
    std::vector<int> myvec = {1, 4, 2, 7, 9, 10};
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::reverse(myvec.begin(), myvec.end());
    std::cout << "after reverse: " << std::endl;
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

/*
1 4 2 7 9 10
after reverse: 
10 9 7 2 4 1
*/
