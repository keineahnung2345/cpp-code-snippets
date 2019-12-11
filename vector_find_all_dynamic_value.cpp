#include <vector>
#include <iostream>
#include <algorithm> //find_if

//https://stackoverflow.com/questions/36474691/c-equivalent-for-passing-a-lambda-function-as-an-argument-in-python

int i = 1;

int main(){
    std::vector<int> v = {3,3,3,3,3,1,3};
    std::vector<int>::iterator iter;
    for(; i <= 3; i++){
        iter = v.begin();
        std::cout << "find " << i << " in vector:" << std::endl;
        while ((iter = std::find_if(iter, v.end(), [](int& el) { return el == i; })) != v.end()){
            std::cout << iter - v.begin() << " ";
            iter++;
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}

/*
find 1 in vector:
5 

find 2 in vector:


find 3 in vector:
0 1 2 3 4 6 


*/
