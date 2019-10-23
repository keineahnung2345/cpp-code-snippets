#include <vector>
#include <iostream>
#include <algorithm> //copy, assign
#include<iterator> // for back_inserter

void cout_vector(std::vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

//https://www.geeksforgeeks.org/ways-copy-vector-c/

int main(){
    std::vector<int> a = {1,2,3,4};
    std::vector<int> b(a); //method 1
    std::vector<int> c = {5,6,7};
    std::vector<int> d;
    std::vector<int> e = {7,8,9};

    //method 2
    c = a;
    //method 3
    std::copy(a.begin(), a.end(), std::back_inserter(d));
    //method 4
    e.assign(a.begin(), a.end());

    cout_vector(b);
    cout_vector(c);
    cout_vector(d);
    cout_vector(e);

    return 0;
}
