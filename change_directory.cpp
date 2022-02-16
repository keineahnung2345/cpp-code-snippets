#include <filesystem>
#include <iostream>

// https://stackoverflow.com/questions/3485166/change-the-current-working-directory-in-c

int main() {
    std::cout << std::filesystem::current_path() << std::endl;
    std::filesystem::current_path("../workspace");
    return 0;
}
