#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

//https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case

int main() {
    std::string str = "Hello WORLD";
    std::string lower_str = boost::algorithm::to_lower_copy(str);
    boost::algorithm::to_lower(str);
    std::cout << str << std::endl;
    return 0;
}
