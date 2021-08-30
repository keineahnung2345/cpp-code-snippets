#include <iostream>
#include <string>
#include <vector>
#include <type_traits> //std::is_scalar

template <typename T>
struct is_scalar_or_std_string { 
    static const bool value = std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value || 
        std::is_scalar<T>::value;
};

int main() {
    std::cout << "std::string is a scalar or string? " << std::boolalpha << is_scalar_or_std_string<std::string>::value << std::endl;
    std::cout << "int is a scalar or string? " << std::boolalpha << is_scalar_or_std_string<int>::value << std::endl;
    std::cout << "std::vector<int> is a scalar or string? " << std::boolalpha << is_scalar_or_std_string<std::vector<int>>::value << std::endl;
    return 0;
}

/**
std::string is a scalar or string? true
int is a scalar or string? true
std::vector<int> is a scalar or string? false
**/
