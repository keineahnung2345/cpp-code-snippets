#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp> //line
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <string>

//https://docs.opencv.org/3.4/d2/de8/group__core__array.html#ga2ac1049c2c3dd25c2b41bffe17658a36

void Show(cv::Mat& img, std::string title = "Display Window"){
    cv::namedWindow( title, cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow(title, img);                   // Show our image inside it.
    cv::waitKey(0);
    cv::destroyAllWindows();
};

void pad(cv::Mat& img, int padt, int padb, int padl, int padr){
    cv::Mat tmp(cv::Size(img.rows+padt+padb, img.cols+padl+padr), CV_8UC1, cv::Scalar(0));
    copyMakeBorder(img, tmp, padt, padb, padl, padr, cv::BORDER_CONSTANT, cv::Scalar(0));
    img = tmp;
};

int main(){
    cv::Mat img = cv::imread("images/Lenna.png", 0);

    int padt = 10, padb = 20, padl = 30, padr = 40;
    pad(img, padt, padb, padl, padr);

    Show(img, "pad");
}
