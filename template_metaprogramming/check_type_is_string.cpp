#include <iostream>
#include <string>
#include <vector>

//https://stackoverflow.com/questions/60929056/c-detect-if-a-type-is-a-string-object
template <typename T>
struct is_std_string : std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string> { };

int main() {
    std::cout << "std::string is a string? " << std::boolalpha << is_std_string<std::string>::value << std::endl;
    std::cout << "int is a string? " << std::boolalpha << is_std_string<int>::value << std::endl;
    std::cout << "std::vector<int> is a string? " << std::boolalpha << is_std_string<std::vector<int>>::value << std::endl;
    return 0;
}

/**
std::string is a string? true
int is a string? false
std::vector<int> is a string? false
**/
