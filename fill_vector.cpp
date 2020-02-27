#include <vector>
#include <iostream>

int main(){
    std::vector<int> myvec = {1,2,3,4,5,6,7,8,9};
    std::fill(myvec.begin(), myvec.end()-1, 5);
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

//5 5 5 5 5 5 5 5 9
