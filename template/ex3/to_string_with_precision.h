// #include <string>
#include <sstream>      // std::ostringstream
/*
Need to #include <sstream> in header file, otherwise: 
error: invalid use of incomplete type ‘std::ostringstream {aka class std::__cxx11::basic_ostringstream<char>}’
*/

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6);

// required to include its implementation
#include "to_string_with_precision.tpp"
