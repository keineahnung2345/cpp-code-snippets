#include <vector>
#include <iostream>
#include <algorithm> //find_if

//https://stackoverflow.com/questions/25846235/finding-the-indexes-of-all-occurrences-of-an-element-in-a-vector

bool isOne(int x){
    return x == 1;
}

int main(){
    std::vector<int> v = {1,1,2,3,1,4};
    std::vector<int>::iterator iter = v.begin();
    while ((iter = std::find_if(iter, v.end(), isOne)) != v.end()){
        std::cout << iter - v.begin() << " ";
        iter++;
    }
    std::cout << std::endl;
    //0 1 4
}  
