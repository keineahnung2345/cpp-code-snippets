#include <vector>
#include <iostream>
#include <sstream> //std::ostringstream

//g++ join.cpp -std=c++11
//https://stackoverflow.com/questions/6097927/is-there-a-way-to-implement-analog-of-pythons-separator-join-in-c

template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& separator)
{
    std::ostringstream result;
    result.precision(2); //for floating point
    if (begin != end)
        result << *begin++;
    while (begin != end)
        //std::fixed : for floating point
        result << std::fixed << separator << *begin++;
    return result.str();
}

int main(){
    std::vector<std::string> vs = {"monkey", "tiger", "horse"};
    std::vector<float> vf = {2.333, 4.2322, 7.2125, 553.3};
    std::vector<bool> vb = {true, false, true, false, false};
    std::cout << join(vs.begin(), vs.end(), ", ") << std::endl;
    std::cout << join(vf.begin(), vf.end(), ", ") << std::endl;
    std::cout << join(vb.begin(), vb.end(), ", ") << std::endl;
}

/*
monkey, tiger, horse
2.3, 4.23, 7.21, 553.30
1, 0, 1, 0, 0
*/
