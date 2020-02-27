#include <vector>
#include <iostream>

//https://stackoverflow.com/questions/20287095/checking-if-all-elements-of-a-vector-are-equal-in-c

int main(){
    std::vector<int> myvec = {1,2,3,4,5,6,7,8,9};
    if(std::adjacent_find(myvec.begin(), myvec.end(), std::not_equal_to<int>()) == myvec.end()){
        std::cout << "All elements are equal each other" << std::endl;
    }else{
        std::cout << "Some elements differ" << std::endl;
    }

    std::fill(myvec.begin(), myvec.end(), 5);
    if(std::adjacent_find(myvec.begin(), myvec.end(), std::not_equal_to<int>()) == myvec.end()){
        std::cout << "All elements are equal each other" << std::endl;
    }else{
        std::cout << "Some elements differ" << std::endl;
    }
    return 0;
}

/*
Some elements differ
All elements are equal each other
*/
