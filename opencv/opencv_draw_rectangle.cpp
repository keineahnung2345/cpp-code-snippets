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

    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return 0;
}
