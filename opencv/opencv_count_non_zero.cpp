#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

/*
This function can only be used on GRAY scale image!!
From https://stackoverflow.com/questions/31231565/countnonzero-function-gives-an-assertion-error-in-opencv
*/

int main(){
    //read in binary image, pixel values are either 0 or 255
    cv::Mat img = cv::imread("binary.png", 0);
    int height = img.rows, width = img.cols;
    std::cout << "image size: " << height << " x " << width << std::endl;
    std::cout << "There are " << cv::countNonZero(img) << " white pixels." << std::endl;
    std::cout << "There are " << width*height - cv::countNonZero(img) << " black pixels." << std::endl;
}

/*
image size: 426 x 653
There are 242138 white pixels.
There are 36040 black pixels.
*/
