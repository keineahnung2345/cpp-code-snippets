#include <algorithm>  // remove_copy_if, remove_if
#include <iostream>
#include <vector>

// https://stackoverflow.com/questions/46236447/efficient-way-to-filter-out-elements-from-stdvector
// https://www.cplusplus.com/reference/algorithm/remove_copy_if/
// https://en.cppreference.com/w/cpp/algorithm/remove
int main() {
    std::vector<float> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<float> v_filtered;
    // remove element < 3 or > 6, copy the remaining elements to v_filtered
    std::remove_copy_if(v.begin(), v.end(), std::back_inserter(v_filtered),
                        [](float ele) { return ele < 3 || ele > 6; });
    for(const auto& ele : v_filtered) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    // 3 4 5 6
    v.erase(std::remove_if(v.begin(), v.end(),
                           [](float ele) { return ele < 3 || ele > 6; }),
            v.end());

    for(const auto& ele : v) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    // 3 4 5 6
    return 0;
}
