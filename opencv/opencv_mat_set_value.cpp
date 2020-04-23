#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp> //minMaxLoc
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

//https://stackoverflow.com/questions/20816955/how-to-set-all-pixels-of-an-opencv-mat-to-a-specific-value
//https://docs.opencv.org/3.4/d2/de8/group__core__array.html#gab473bf2eb6d14ff97e89b355dac20707

int main(){
    double minVal, maxVal; //must be of type "double" !
    cv::Point minLoc, maxLoc;

    cv::Mat mat(cv::Size(100, 100), CV_8UC1, cv::Scalar(0));
    //Method 1
    mat.setTo(255);
    cv::minMaxLoc(mat, &minVal, &maxVal);
    cv::minMaxLoc(mat, &minVal, &maxVal, &minLoc, &maxLoc);

    std::cout << minVal << " " << maxVal << std::endl;

    //Method 2
    mat = cv::Scalar::all(0);
    cv::minMaxLoc(mat, &minVal, &maxVal);
    cv::minMaxLoc(mat, &minVal, &maxVal, &minLoc, &maxLoc);
    std::cout << minVal << " " << maxVal << std::endl;
}

/*
255 255
0 0
*/
