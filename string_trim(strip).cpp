#include <algorithm>
#include <iostream>

//https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

// trim from start (in place)
static inline void trim_left(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void trim_right(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim_all(std::string &s) {
    trim_left(s);
    trim_right(s);
}

// trim from start (copying)
static inline std::string trim_left_copy(std::string s) {
    trim_left(s);
    return s;
}

// trim from end (copying)
static inline std::string trim_right_copy(std::string s) {
    trim_right(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_all_copy(std::string s) {
    trim_all(s);
    return s;
}

// g++ string_trim\(strip\).cpp -std=c++11

int main(){
    std::string str = "   hello world!   ";
    std::cout << "trim left: '" << trim_left_copy(str) << "'" << std::endl;
    std::cout << "trim right: '" << trim_right_copy(str) << "'" << std::endl;
    std::cout << "trim all: '" << trim_all_copy(str) << "'" << std::endl;
    trim_left(str);
    std::cout << "trim left(in-place): '" << str << "'" << std::endl;
    trim_right(str);
    std::cout << "trim right(in-place): '" << str << "'" << std::endl;
    return 0;
}

/*
trim left: 'hello world!   '
trim right: '   hello world!'
trim all: 'hello world!'
trim left(in-place): 'hello world!   '
trim right(in-place): 'hello world!'
*/
