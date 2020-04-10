#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3

//https://docs.opencv.org/3.4/d6/d50/classcv_1_1Size__.html

int main(){
    int width = 100, height = 200;
    //width first and then height!
    cv::Mat c1 = cv::Mat(cv::Size(width, height), CV_8UC1, cv::Scalar(0));
    cv::Mat c3 = cv::Mat(cv::Size(width, height), CV_8UC3, cv::Vec3b(0, 0, 0));
    return 0;
}
