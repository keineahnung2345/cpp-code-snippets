#include <iostream>
#include "opencv2/opencv.hpp"

//https://stackoverflow.com/questions/17363886/can-i-determine-the-number-of-channels-in-cvmat-opencv

int main()
{
    cv::Mat src = cv::imread("path_to_image");
    std::cout << src.type() << ", " << src.channels() << std::endl;
    return 0;
}
