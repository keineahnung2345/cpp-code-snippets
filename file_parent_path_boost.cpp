#include <vector>
#include <string>
#include <iostream>

#include <boost/filesystem.hpp>

using namespace std;

int main(int argc, char** argv) {
    boost::filesystem::path p("C:\\folder\\foo.txt");
    boost::filesystem::path dir = p.parent_path();
    std::cout << "dir: " << dir << std::endl; //dir: "C:\folder"

    return 0;
}
