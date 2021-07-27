#include <vector>
#include <string>
#include <iostream>

//https://en.cppreference.com/w/cpp/language/template_specialization
//https://zhuanlan.zhihu.com/p/72356532

using namespace std;

template <typename T>
std::string serialize(const T& var) {
    return std::to_string(var);
}

template<>
std::string serialize<std::string>(const std::string& var) {
    return '"' + var + '"';
}

int main(int argc, char** argv) {
    string sf, ss;
    sf = serialize(1.2345);
    ss = serialize(string("hello world"));
    cout << sf << endl; // 1.234500
    cout << ss << endl; // "hello world"

    return 0;
}
