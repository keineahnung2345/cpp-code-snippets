#include <algorithm>
#include <iostream>
#include <vector>

// https://stackoverflow.com/questions/11343116/rotating-a-vector-array

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    std::rotate(v.begin(),
                v.end() - 1,  // this will be the new first element
                v.end());

    for(int i : v) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
