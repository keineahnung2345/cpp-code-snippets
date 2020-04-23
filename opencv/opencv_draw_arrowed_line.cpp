#include <opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <iostream>

//https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#ga0a165a3ca093fd488ac709fdf10c05b2

void Show(cv::Mat& img, std::string title = "Display Window"){
    cv::namedWindow( title, cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow(title, img);                   // Show our image inside it.
    cv::waitKey(0);
    cv::destroyAllWindows();
};

int main(){
    cv::Mat img = cv::imread("Lenna.png", 0);
    int thickness = 2;
    int r = 112, c = 414;
    //cv::Point: (x, y), in which x moves left-right, y moves top-down
    cv::arrowedLine(img, cv::Point(c-30, r-30), cv::Point(c, r), cv::Scalar(0), thickness);
    Show(img, "arrowed line");
}
