#include <vector>
#include <iostream>
#include <numeric> //accumulate
#include <functional> //multiplies

int main(){
    std::vector<int> myvec = {1,2,3,4,5,6};
    int cumprod = std::accumulate(myvec.begin(), myvec.end(), 1, std::multiplies<int>());
    std::cout << cumprod << std::endl; //720
    return 0;
}
