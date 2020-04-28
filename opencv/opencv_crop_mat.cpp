#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    cv::Mat img = cv::imread("face.jpeg");
    //x and w in left-right direction, y and h in top-down direction
    int x = 97, y = 0, w = 224 - 97, h = 118 - 0;
    cv::Mat roi = img(cv::Rect(x, y, w, h));
    std::cout << "original image size: " << img.size << std::endl;
    std::cout << "cropped image size: " << roi.size << std::endl;
    std::cout << "cropped image rows: " << roi.rows << ", cols: " << roi.cols << std::endl;
    //original image size: 173 x 292
    //cropped image size: 118 x 127
    //cropped image rows: 118, cols: 127
}
