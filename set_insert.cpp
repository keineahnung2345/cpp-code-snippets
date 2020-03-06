#include <set>
#include <iostream>
#include <utility> //pair

int main(){
    std::set<int> myset = {1,2,3};
    std::pair<std::set<int>::iterator, bool> result = myset.insert(4);
    std::cout << "4 already exist? " << result.second << std::endl;
    result = myset.insert(4);
    std::cout << "4 already exist? " << result.second << std::endl;
    return 0;
}
