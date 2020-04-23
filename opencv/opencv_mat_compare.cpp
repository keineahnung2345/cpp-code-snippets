#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

//https://stackoverflow.com/questions/25660020/compare-2-cvmat/25660345

int main(){
    //8UC1 mat initialize from unsinged char array
    unsigned char mat1V[3][3] = {
        {0,255,255},
        {255,255,0},
        {255,0,255}
    };

    unsigned char mat2V[9] = {
        255,0,255,
        255,0,0,
        0,0,255
    };
    cv::Mat mat1(cv::Size(3, 3), CV_8UC1, mat1V);
    cv::Mat mat2(cv::Size(3, 3), CV_8UC1, mat2V);
    cv::Mat mat3 = mat1;

    cv::Mat diff;

    std::cout << "Matrix 1: " << std::endl;
    std::cout << mat1 << std::endl;
    std::cout << "Matrix 2: " << std::endl;
    std::cout << mat2 << std::endl;
    cv::bitwise_xor(mat1, mat2, diff);
    if(cv::countNonZero(diff) > 0){
        std::cout << "The two mat are different." << std::endl;
    }else{
        std::cout << "The two mat are same." << std::endl;
    }

    std::cout << "Matrix 1: " << std::endl;
    std::cout << mat1 << std::endl;
    std::cout << "Matrix 3: " << std::endl;
    std::cout << mat3 << std::endl;
    cv::bitwise_xor(mat1, mat3, diff);
    if(cv::countNonZero(diff) > 0){
        std::cout << "The two mat are different." << std::endl;
    }else{
        std::cout << "The two mat are same." << std::endl;
    }
}

/*
Matrix 1: 
[  0, 255, 255;
 255, 255,   0;
 255,   0, 255]
Matrix 2: 
[255,   0, 255;
 255,   0,   0;
   0,   0, 255]
The two mat are different.
Matrix 1: 
[  0, 255, 255;
 255, 255,   0;
 255,   0, 255]
Matrix 3: 
[  0, 255, 255;
 255, 255,   0;
 255,   0, 255]
The two mat are same.
*/
