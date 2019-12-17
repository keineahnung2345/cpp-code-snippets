#include <vector>
#include <iostream>

int main(){
    std::vector<std::vector<int>> v = {{1,2}, {3,4}};
    //e2 isn't linked to v in this way
    //std::vector<int>& e1 = v[0], e2 = v[1];
    //both e1 and e2 are linked to v
    std::vector<int> &e1 = v[0], &e2 = v[1];

    e1[0] = -1;
    e2[1] = -2;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
