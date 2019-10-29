#include <iostream>
#include <vector>
#include <algorithm> //copy

int main(){
    std::vector<int> vec = {1,2,3,4,5};
    int arr[vec.size()];
    std::copy(vec.begin(), vec.end(), arr);
    std::cout << "size of arr: " << sizeof(arr) << ", size of its first element: " << sizeof(arr[0]) << std::endl;
    arr[0] = -1;
    std::cout << "arr:" << std::endl;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "vec:" << std::endl;
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*
size of arr: 20, size of its first element: 4
arr:
-1 2 3 4 5 
vec:
1 2 3 4 5
*/
