#include <string>
#include <filesystem> //C++17

//https://stackoverflow.com/questions/8520560/get-a-file-name-from-a-path
//C++17
//https://en.cppreference.com/w/cpp/filesystem/path/stem

int main() {
    std::string filename = "C:\\MyDirectory\\MyFile.bat";

    // Remove directory if present.
    // Do this before extension removal incase directory has a period character.
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        filename.erase(0, last_slash_idx + 1);
    }

    // Remove extension if present.
    const size_t period_idx = filename.rfind('.');
    if (std::string::npos != period_idx)
    {
        filename.erase(period_idx);
    }
    
    // or in C++17
    std::cout << std::filesystem::path(filename).stem().string() << std::endl;
    
    return 0;
}
