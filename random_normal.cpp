#include <iostream>
#include <random>

//http://www.cplusplus.com/reference/random/normal_distribution/normal_distirbution/

int main(){
    std::default_random_engine generator;
    double mean = 0.0, stddev = 1.0;
    std::normal_distribution<double> distribution(mean, stddev);
    for(int i = 0; i < 100; i++){
        std::cout << distribution(generator) << " "; 
    }
    std::cout << std::endl;
    
    return 0;
}
