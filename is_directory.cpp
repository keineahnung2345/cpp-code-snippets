#include <string>
#include <iostream>
#include <filesystem>

//C++17
//https://en.cppreference.com/w/cpp/filesystem/is_directory

int main(int argc, char** argv) {
    std::string path = "../";
    std::cout << path << " is dir? " << std::filesystem::is_directory(path) << std::endl;
    return 0;
}
