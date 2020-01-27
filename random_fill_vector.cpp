#include <vector>
#include <iostream>

//https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c

int main(){
    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), std::rand);
    for(size_t i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

//16807 282475249 1622650073 984943658 1144108930 470211272 101027544 1457850878 1458777923 2007237709
