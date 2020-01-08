#include <iostream>
#include <vector>
#include <algorithm> //remove_if, distance

//https://stackoverflow.com/questions/23122555/removing-by-index-from-a-c-vector-using-remove-if
//https://stackoverflow.com/questions/54675992/alternatives-to-vector-size-after-running-remove-if

int main(){
    std::vector<int> data = {6,3,7,2,1,9};

    std::cout << "original vector: " << std::endl;
    for(int d : data){
        std::cout << d << " ";
    }
    std::cout << std::endl;

    std::cout << "performing remove_if..." << std::endl;
    //[&data]: lambda function capture list
    std::vector<int>::iterator new_end = std::remove_if(data.begin(), data.end(),
               [&data](const int& d) { return (&d - &*data.begin()) % 2; });

    // cannot use data.size() after remove_if!
    std::cout << "wrong size after remove_if: " << data.size() << std::endl;

    size_t new_size = std::distance(data.begin(), new_end);
    std::cout << "correct size after remove_if: " << new_size << std::endl;

    data.resize(new_size);

    std::cout << "vector after remove_if: " << std::endl;
    for(int d : data){
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
6 3 7 2 1 9 
performing remove_if...
wrong size after remove_if: 6
correct size after remove_if: 3
vector after remove_if: 
6 7 1 
*/
