#include <filesystem>
#include <iostream>

// https://stackoverflow.com/questions/875249/how-to-get-current-directory

int main() {
	std::filesystem::path cwd = std::filesystem::current_path();
	std::cout << "current dir: " <<  cwd << std::endl;
	return 0;
}
