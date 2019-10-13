#include <iostream>
#include "opencv2/opencv.hpp"

//https://stackoverflow.com/questions/21659496/deep-copy-of-opencv-cvmat

int main()
{
    cv::Mat src = cv::imread("path_to_image");
    cv::Mat dst = src.clone(); 
    return 0;
}
