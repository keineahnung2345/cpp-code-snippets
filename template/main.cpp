#include <vector>
#include <iostream>
#include <utils.h>

//g++ main.cpp utils.cpp -I . -std=c++11
//g++ main.cpp utils.cpp -I . -std=c++11 -DCORRECT

int main(){
    std::vector<std::string> vs = {"monkey", "tiger", "horse"};
    std::vector<float> vf = {2.333, 4.2322, 7.2125, 553.3};
    std::cout << join(vs.begin(), vs.end(), ", ") << std::endl;
    std::cout << join(vf.begin(), vf.end(), ", ") << std::endl;
    return 0;
}
