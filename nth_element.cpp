#include <vector>
#include <iostream>

//https://en.cppreference.com/w/cpp/algorithm/nth_element

int main(){
    std::vector<int> myvec = {1,3,6,2,9,5};
    int n = 3;
    std::nth_element(myvec.begin(), myvec.begin()+n, myvec.end(), std::greater<int>());
    std::cout << "The " << n << " largest values are : ";
    for(int i = 0; i < n; i++){
        std::cout << myvec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

//The 3 largest values are : 9 6 5
