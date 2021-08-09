#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

int main(int argc, char** argv) {
    std::string filePath = "C:\\Users\\mimif\\Documents\\a.txt";
    std::cout << boost::filesystem::exists(filePath) << std::endl; //1

    return 0;
}
