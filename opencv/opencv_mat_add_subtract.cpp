#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

//https://docs.opencv.org/4.3.0/d2/de8/group__core__array.html#ga10ac1bfb180e2cfda1701d06c24fdbd6

int main(){
    int width = 100, height = 200;
    int p1 = 100, p2 = 200;
    cv::Mat img1 = cv::Mat(cv::Size(width, height), CV_8UC1, cv::Scalar(p1));
    cv::Mat img2 = cv::Mat(cv::Size(width, height), CV_8UC1, cv::Scalar(p2));
    cv::Mat img1sub2, img2sub1;
    cv::subtract(img1, img2, img1sub2); //the min will be 0
    std::cout << p1 << " - " << p2 << ": " << (int)img1sub2.at<uchar>(0, 0) << std::endl;
    cv::subtract(img2, img1, img2sub1);
    std::cout << p1 << " - " << p2 << ": " << (int)img2sub1.at<uchar>(0, 0) << std::endl;
    cv::Mat img1add2;
    cv::add(img1, img2, img1add2); //the max will be 255
    std::cout << p1 << " + " << p2 << ": " << (int)img1add2.at<uchar>(0, 0) << std::endl;
    return 0;
}

/*
100 - 200: 0
100 - 200: 100
100 + 200: 255
*/
