#include <vector>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

//g++ glob.cpp `pkg-config --cflags --libs opencv4` -std=c++11

int main(){
    std::string pattern = "/xxx/*.cpp";
    std::vector<std::string> fnames;
    //not recursive
    //cv::glob(pattern, fnames, false);
    //recursive
    cv::glob(pattern, fnames, true);
    for(std::string fname : fnames){
        std::cout << fname << std::endl;
    }
    return 0;
}
