#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

//https://answers.opencv.org/question/27248/max-and-min-values-in-a-mat/

int main(){
    cv::Mat img = cv::imread("Lenna.png", 0);
    int height = img.rows, width = img.cols;
    
    double minVal, maxVal; //must be of type "double" !
    cv::Point minLoc, maxLoc;

    cv::minMaxLoc(img, &minVal, &maxVal);
    std::cout << "Pixel values range from : " << minVal << " to " << maxVal << std::endl;
    cv::minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc);
    //y first and then x!
    std::cout << "Min value's position: (" << minLoc.x << ", " << minLoc.y << "), value: " << (int)img.at<uchar>(minLoc.y, minLoc.x) << std::endl;
    std::cout << "Max value's position: (" << maxLoc.x << ", " << maxLoc.y << "), value: " << (int)img.at<uchar>(maxLoc.y, maxLoc.x) << std::endl;
}

/*
Pixel values range from : 24 to 245
Min value's position: (508, 71), value: 24
Max value's position: (116, 273), value: 245
*/
