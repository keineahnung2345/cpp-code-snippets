#include <string>
#include <boost/filesystem.hpp>

int main(){
    std::string basename = boost::filesystem::path("C:/MyDirectory/MyFile.bat").filename().string();
    return 0;
}
