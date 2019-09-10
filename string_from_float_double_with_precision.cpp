#include <iostream>
#include <sstream>
using namespace std;

//https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}
 
int main() {
	double d = 12.123456789;
	float f = 4.123456;
	std::cout << d << " becomes: " << to_string_with_precision(d, 3) << std::endl;
	std::cout << f << " becomes: " << to_string_with_precision(f, 2) << std::endl;
 
	return 0;
}
