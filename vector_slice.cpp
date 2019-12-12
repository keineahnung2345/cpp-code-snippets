#include <vector>
#include <iostream>

int main(){
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(v1.begin()+1, v1.end()-1);
    for(int e : v2){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    //2 3 4
    return 0;
}
