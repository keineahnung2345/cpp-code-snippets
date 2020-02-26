#include <vector>
#include <iostream>

//https://stackoverflow.com/questions/12990148/get-all-positions-of-elements-in-stl-vector-that-are-greater-than-a-value
//find the index that meets a requirement

int main(){
    std::vector<int> myvec = {1, 3, 2, 7, 4, 9, 5};
    std::vector<size_t> results;

    auto it = std::find_if(std::begin(myvec), std::end(myvec), [](int i){return i > 5;});
    while (it != std::end(myvec)) {
       results.emplace_back(std::distance(std::begin(myvec), it));
       it = std::find_if(std::next(it), std::end(myvec), [](int i){return i > 5;});
    }
    std::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

//3 5
