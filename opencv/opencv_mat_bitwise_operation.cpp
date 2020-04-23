#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

#define MODE FLOAT

//https://stackoverflow.com/questions/43180053/initialize-the-values-into-mat-object-in-opencv
//http://opencvexamples.blogspot.com/2013/10/bitwise-and-or-xor-and-not.html

int main(){
#if MODE == FLOAT
    //32FC1 mat initialize from float array
    float mat1V[3][3] = {
        {0,255,255},
        {255,255,0},
        {255,0,255}
    };

    float mat2V[9] = {
        255,0,255,
        255,0,0,
        0,0,255
    };

    cv::Mat mat1(cv::Size(3, 3), CV_32FC1, mat1V);
    cv::Mat mat2(cv::Size(3, 3), CV_32FC1, mat2V);
#else
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
#endif

    cv::Mat andRes, orRes, xorRes;

    cv::bitwise_and(mat1, mat2, andRes);
    cv::bitwise_or(mat1, mat2, orRes);
    cv::bitwise_xor(mat1, mat2, xorRes);

    std::cout << "Matrix 1: " << std::endl;
    std::cout << mat1 << std::endl;
    std::cout << "Matrix 2: " << std::endl;
    std::cout << mat2 << std::endl;
    std::cout << "And: " << std::endl;
    std::cout << andRes << std::endl;
    std::cout << "Or: " << std::endl;
    std::cout << orRes << std::endl;
    std::cout << "Xor: " << std::endl;
    std::cout << xorRes << std::endl;
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
And: 
[  0,   0, 255;
 255,   0,   0;
   0,   0, 255]
Or: 
[255, 255, 255;
 255, 255,   0;
 255,   0, 255]
Xor: 
[255, 255,   0;
   0, 255,   0;
 255,   0,   0]
*/
