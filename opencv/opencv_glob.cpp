#include <opencv2/opencv.hpp>

//https://blog.csdn.net/qq_31261509/article/details/79460639

int main(){
    std::string dir = "*.sh";
    std::vector<std::string> filenames;
    bool recursive = false;

    cv::glob(dir, filenames, recursive);
    for(int i = 0; i < filenames.size(); i++){
        std::cout << filenames[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
