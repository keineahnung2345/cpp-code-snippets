#include <string>
#include <iomanip>
#include <iostream>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
};
