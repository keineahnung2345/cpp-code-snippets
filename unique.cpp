#include <iostream>
#include <algorithm>
#include <vector>

//https://stackoverflow.com/questions/28100712/better-way-of-counting-unique-item

int main() {
    // your code goes here
    std::vector<int> myvec = {1,3,3,4,2,6,2};
    std::sort(myvec.begin(), myvec.end());
    std::vector<int>::iterator it = std::unique(myvec.begin(), myvec.end());
    int unique_count = std::distance(myvec.begin(),it);
    myvec.resize(unique_count);
    
    std::cout << "unique count: " << myvec.size() << std::endl;
    for(int i = 0; i < myvec.size(); i++){
        std::cout << myvec[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

/*
unique count: 5
1 2 3 4 6 
*/
