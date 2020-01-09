#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <iostream>

int main(){
    std::string str("    hello world! ");
    std::cout << "original: '" << str << "'" << std::endl;
    std::cout << "trimed from right: '" << boost::trim_right_copy(str) << "'" << std::endl;
    std::cout << "trimed from left: '" << boost::trim_left_copy(str) << "'" << std::endl;
    std::cout << "trimed from left and right: '" << boost::trim_all_copy(str) << "'" << std::endl;
    boost::trim_right(str);
    std::cout << "trimed from right(in-place): '" << str << "'" << std::endl;
    boost::trim_left(str);
    std::cout << "trimed from left(in-place): '" << str << "'" << std::endl;
}

/*
original: '    hello world! '
trimed from right: '    hello world!'
trimed from left: 'hello world! '
trimed from left and right: 'hello world!'
trimed from right(in-place): '    hello world!'
trimed from left(in-place): 'hello world!'
*/
