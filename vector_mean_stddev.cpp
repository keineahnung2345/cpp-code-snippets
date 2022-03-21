#include <iostream>
#include <vector>
#include <cmath> // sqrt
#include <numeric> // accumulate
#include <algorithm> // transform, inner_product

// https://stackoverflow.com/questions/7616511/calculate-mean-and-standard-deviation-from-a-vector-of-samples-in-c-using-boos

void calculateMinMaxAvgStddev(const std::vector<float>& v, float& min_,
                              float& max_, float& avg, float& stddev) {
    min_ = *std::min_element(v.begin(), v.end());
    max_ = *std::max_element(v.begin(), v.end());
    avg  = std::accumulate(v.begin(), v.end(), 0.0f) / v.size();

    std::vector<float> diffs;
    std::transform(v.begin(), v.end(), std::back_inserter(diffs),
                   [avg](float x) { return x - avg; });
    float sq_sum =
        std::inner_product(diffs.begin(), diffs.end(), diffs.begin(), 0.0);
    stddev = std::sqrt(sq_sum / v.size());
}

int main() {
    std::vector<float> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float              min_, max_, avg, stddev;
    calculateMinMaxAvgStddev(v, min_, max_, avg, stddev);
    std::cout << "min: " << min_ << std::endl;
    std::cout << "max: " << max_ << std::endl;
    std::cout << "avg: " << avg << std::endl;
    std::cout << "stddev: " << stddev << std::endl;
    return 0;
}

/*
min: 1
max: 10
avg: 5.5
stddev: 2.87228
*/
