#include <iostream>
#include <vector>
#include <algorithm> //max_element

int main() {
    std::vector<int> myvec = {1,3,2,4,5,9,4,2,9,3,2,6,3,6,8,9,7,5,3,6};
    int maxValue = *max_element(myvec.begin(), myvec.end());
	
    std::cout << std::count_if(myvec.begin(), myvec.end(), 
        [&maxValue](int n){return n == maxValue;}) << std::endl; //3
    return 0;
}
