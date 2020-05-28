#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert> //assert

//https://stackoverflow.com/questions/9445327/fast-way-to-implement-pop-front-to-a-stdvector

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

int main() {
    std::vector<int> vec = {1,2,3,4,5,6};
    pop_front(vec);
    
    for(int e : vec){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

//2 3 4 5 6 
