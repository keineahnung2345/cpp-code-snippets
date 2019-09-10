#include <iostream>
#include <random>

using namespace std;

//https://stackoverflow.com/questions/39319963/c-randomly-select-from-string-array

int main() {
    double alphas[] = {0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    for(int i = 0; i < 100; i++){
        std::cout << alphas[rand() % 7] << std::endl;
    }
    return 0;
}
