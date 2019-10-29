#include <iostream>
#include "opencv2/opencv.hpp"

//https://stackoverflow.com/questions/40120433/draw-rectangle-in-opencv

int main()
{
    cv::Mat img = cv::imread("path_to_image");
    int x = 0;
    int y = 0;
    int width = 10;
    int height = 20;

    //method 1
    cv::Point pt1(x, y);
    cv::Point pt2(x + width, y + height);
    cv::rectangle(img, pt1, pt2, cv::Scalar(0, 255, 0));
    //method 2
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return 0;
}
