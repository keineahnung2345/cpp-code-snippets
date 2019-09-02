#include <iostream>
#include "opencv2/opencv.hpp"

//https://stackoverflow.com/questions/32971241/how-to-get-image-width-and-height-in-opencv/32971309

int main()
{
    cv::Mat src = cv::imread("path_to_image");
    std::cout << "Width : " << src.cols << std::endl;
    std::cout << "Height: " << src.rows << std::endl;
    return 0;
}
