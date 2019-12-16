#include <iostream>
#include <vector>
#include <algorithm>

//https://stackoverflow.com/questions/8848575/fastest-way-to-reset-every-value-of-stdvectorint-to-0

int main(){
    std::vector<int> v(5);
    v[2]++;
    v[3]--;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::fill(v.begin(), v.end(), 0);

    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
