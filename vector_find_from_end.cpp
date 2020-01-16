#include <algorithm>
#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/24997910/get-index-in-vector-from-reverse-iterator

int main(){
    std::vector<int> v = {1, 2, 3, 3, 4, 2, 6};
    std::vector<int>::reverse_iterator rit = std::find(v.rbegin(), v.rend(), 3);
    if(rit != v.rend()){
        int idx = std::distance(begin(v), rit.base()) - 1;
        std::cout << idx << std::endl;
    }else{
        std::cout << "not found!" << std::endl;
    }
}

/*
3
*/
