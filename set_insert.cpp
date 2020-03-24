#include <set>
#include <iostream>
#include <utility> //pair

int main(){
    std::set<int> myset = {1,2,3};
    std::pair<std::set<int>::iterator, bool> result = myset.insert(4);
    std::cout << "4 [already exist/successfully inserted](0/1)? " << result.second << std::endl;
    result = myset.insert(4);
    std::cout << "4 [already exist/successfully inserted](0/1)? " << result.second << std::endl;
    return 0;
}
/*
4 [already exist/successfully inserted](0/1)? 1
4 [already exist/successfully inserted](0/1)? 0
*/
