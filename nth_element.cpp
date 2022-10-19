#include <vector>
#include <iostream>
#include <algorithm> //nth_element

//https://en.cppreference.com/w/cpp/algorithm/nth_element

/*
It only put the nth largest/smallest element in the right position
, other elements may not in sorted position!
*/
int main(){
    std::vector<int> myvec = {1,3,6,2,9,5};
    int n = 3;
    std::nth_element(myvec.begin(), myvec.begin()+n, myvec.end(), std::greater<int>());
    std::cout << "The " << n << " largest values are : ";
    for(int i = 0; i < n; i++){
        std::cout << myvec[i] << " ";
    }
    std::cout << std::endl;
    
    myvec = {1,3,6,2,9,5};
    n = 1;
    std::nth_element(myvec.begin(), myvec.begin()+n, myvec.end(), std::greater<int>());
    std::cout << "The largest element is " << myvec[0] << '\n';
    std::cout << "The second largest element is " << myvec[1] << '\n';
    return 0;
}

//The 3 largest values are : 6 9 5 
