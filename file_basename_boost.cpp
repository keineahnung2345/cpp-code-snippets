#include <string>
#include <boost/filesystem.hpp>

//https://stackoverflow.com/questions/8520560/get-a-file-name-from-a-path

int main(){
    std::string basename = boost::filesystem::path("C:/MyDirectory/MyFile.bat").filename().string();
    return 0;
}
