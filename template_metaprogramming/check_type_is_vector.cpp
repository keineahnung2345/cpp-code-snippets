#include <type_traits>
#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector
//https://stackoverflow.com/questions/30468402/colon-after-struct-name-with-data-type
//https://stackoverflow.com/questions/58694521/what-is-stdfalse-type-or-stdtrue-type

//the colon after struct name means "inherits from"
template<typename>
struct is_std_vector : std::false_type {};

template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

int main()
{
    typedef std::vector<int> vec;
    typedef int not_vec;
    std::cout << "std::vector<int> is std::vector? " << is_std_vector<vec>::value << std::endl;
    std::cout << "int is std::vector? " << is_std_vector<not_vec>::value << std::endl;
}

/**
std::vector<int> is std::vector? 1
int is std::vector? 0
**/
