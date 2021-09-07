#include <string>
#include <iostream>
#include <filesystem>

//C++17
//https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

int main(int argc, char** argv) {
    std::string parent_path = "../";
    for (const std::filesystem::path& path : std::filesystem::directory_iterator(parent_path)) {
        std::string spath = path.string();
        std::cout << spath << std::endl;
    }

    return 0;
}
