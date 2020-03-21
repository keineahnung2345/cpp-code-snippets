#include <iostream>
#include <map>

int main(void) {
    std::map<char, int, std::greater<char>> mymap = {{'a', 1}, {'b', 3}, {'c', 3}};
    
    for(auto it = mymap.begin(); it != mymap.end(); it++){
    	std::cout << it->first << " " << it->second << std::endl;
    }
    
    return 0;
}

/*
c 3
b 3
a 1
*/
