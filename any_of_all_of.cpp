#include <iostream>
#include <vector>
#include <algorithm> //std::any_of

//http://www.cplusplus.com/reference/algorithm/any_of/
//http://www.cplusplus.com/reference/algorithm/all_of/

int main() {
    std::vector<bool> vec = {false, true, false};
 
    if(std::any_of(vec.begin(), vec.end(), [](const bool& b){return b;})){
        std::cout << "There is at least one true!" << std::endl;
    }else{
        std::cout << "They are all false!" << std::endl;
    }
 
    vec = {false, false, false};
 
    if(std::any_of(vec.begin(), vec.end(), [](const bool& b){return b;})){
        std::cout << "There is at least one true!" << std::endl;
    }else{
        std::cout << "They are all false!" << std::endl;
    }
 
    vec = {true, true, false};
 
    if(std::all_of(vec.begin(), vec.end(), [](const bool& b){return b;})){
        std::cout << "They are all true!" << std::endl;
    }else{
        std::cout << "There is at least one false!" << std::endl;
    }
 
    return 0;
}

/*
There is at least one true!
They are all false!
There is at least one false!
*/
