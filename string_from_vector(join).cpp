#include <vector>
#include <iostream>
#include <sstream> //std::ostringstream
#include <numeric> //accumulate

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

//https://stackoverflow.com/questions/9277906/stdvector-to-string-with-custom-delimiter
//can only be used with container of string
template <typename Iter>
std::string join2(Iter begin, Iter end, std::string const& separator) {
    return std::accumulate(begin, end, std::string(),
        [&separator](std::string& ss, std::string& s)
        {
            return ss.empty() ? s : ss + separator + s;
        });
}

int main(){
    std::vector<std::string> vs = {"monkey", "tiger", "horse"};
    std::vector<float> vf = {2.333, 4.2322, 7.2125, 553.3};
    std::vector<bool> vb = {true, false, true, false, false};
    std::cout << join(vs.begin(), vs.end(), ", ") << std::endl;
    std::cout << join(vf.begin(), vf.end(), ", ") << std::endl;
    std::cout << join(vb.begin(), vb.end(), ", ") << std::endl;
    
    std::vector<std::string> vs = { "hello", "goodbye", "thanks" };
    std::string res = join(vs.begin(), vs.end(), "-");
    std::cout << res << std::endl; //hello-goodbye-thanks
}

/*
monkey, tiger, horse
2.3, 4.23, 7.21, 553.30
1, 0, 1, 0, 0
*/
