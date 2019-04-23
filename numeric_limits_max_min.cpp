#include <iostream>
#include <limits>

using namespace std;

//https://en.cppreference.com/w/cpp/types/numeric_limits/lowest

int main() {
	cout << "Minimum value for uint32_t: " << numeric_limits<uint32_t>::min() << endl;
	cout << "Maximum value for uint32_t: " << numeric_limits<uint32_t>::max() << endl;
	cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;
	cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;
	/**
	 * Minimum value for uint32_t: 0
	 Maximum value for uint32_t: 4294967295
	 Minimum value for double: 2.22507e-308
	 Maximum value for double: 1.79769e+308
	 **/
	return 0;
}
