#include <boost/algorithm/string/predicate.hpp>

//https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c

int main(){
    std::cout << boost::algorithm::ends_with("mystring", "ing") << std::endl;
    return 0;
}
