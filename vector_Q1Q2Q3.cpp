#include <algorithm>  // nth_element
#include <iostream>
#include <vector>

// https://stackoverflow.com/questions/11964552/finding-quartiles

void calculateQ1Q2Q3(std::vector<float> v, float& Q1, float& Q2, float& Q3) {
    auto const Q1_idx = v.size() / 4;
    auto const Q2_idx = v.size() / 2;
    auto const Q3_idx = Q1_idx + Q2_idx;

    // nth_element will partial sort the input vector
    std::nth_element(v.begin(), v.begin() + Q1_idx, v.end());
    std::nth_element(v.begin() + Q1_idx + 1, v.begin() + Q2_idx, v.end());
    std::nth_element(v.begin() + Q2_idx + 1, v.begin() + Q3_idx, v.end());

    Q1 = v[Q1_idx];
    Q2 = v[Q2_idx];
    Q3 = v[Q3_idx];
}

int main() {
    std::vector<float> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float Q1, Q2, Q3;
    calculateQ1Q2Q3(v, Q1, Q2, Q3);
    std::cout << "Q1: " << Q1 << std::endl;
    std::cout << "Q2: " << Q2 << std::endl;
    std::cout << "Q3: " << Q3 << std::endl;
    return 0;
}

/*
Q1: 3
Q2: 6
Q3: 8
*/
