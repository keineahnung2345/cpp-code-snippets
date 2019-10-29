#include <opencv2/imgcodecs.hpp> //imread, imwrite
#include <opencv2/imgproc.hpp> //cvtColor

//g++ cv_write.cpp `pkg-config --cflags --libs opencv4` -std=c++11

int main(){
    cv::Mat src = cv::imread("face.jpg");
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_RGB2BGR);
    cv::imwrite("face_reverted.jpg", dst);
    return 0;
}
