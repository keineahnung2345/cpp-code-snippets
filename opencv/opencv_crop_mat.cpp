#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("face.jpeg");
    int x = 97, y = 0, w = 224 - 97, h = 118 - 0;
    cv::Mat roi = img(cv::Rect(x, y, w, h));
    std::cout << "original image size: " << img.size << std::endl;
    std::cout << "cropped image size: " << roi.size << std::endl;
    //original image size: 173 x 292
    //cropped image size: 118 x 127
}
