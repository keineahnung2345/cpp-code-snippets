#include <iostream>
#include <vector>
#include <cmath> //round

int main() {
    std::vector<double> myvec = {2.3, 5.5, 7.8, -2.3, -5.5, -7.8};
    for(double d : myvec){
        std::cout << d << "->" << round(d) << std::endl;
    }
    return 0;
}

/*
2.3->2
5.5->6
7.8->8
-2.3->-2
-5.5->-6
-7.8->-8
*/
