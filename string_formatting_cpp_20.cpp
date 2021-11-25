#include <format>
#include <string>
#include <iostream>

int main() {
	std::string s1 = "Line no. ";
	std::cout << std::format("{}:{:4d}:{}", s1, 1, 3.14) << std::endl;
	std::cout << std::format("{}:{:4d}:{}", s1, 199, 3.14) << std::endl;
	std::cout << std::format("{}:{:4d}:{}", s1, 1234, 3.14) << std::endl;
	return 0;
}

/**
Line no. :   1:3.14
Line no. : 199:3.14
Line no. :1234:3.14
*/
