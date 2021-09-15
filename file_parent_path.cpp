#include <iostream>
#include <string>

std::string get_parent_path(const std::string& path){
    size_t pos = path.rfind('\\');
    if (std::string::npos == pos) pos = path.rfind('/');
    return path.substr(0, pos);
}

int main() {
    std::cout << get_parent_path("/home/my/path/file.txt") << std::endl;
    std::cout << get_parent_path("C:\\my\\path\\file.txt") << std::endl;
    return 0;
}

/**
home/my/path
C:\my\path
**/
