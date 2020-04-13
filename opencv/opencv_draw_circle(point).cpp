#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp> //line
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <string>

void Show(cv::Mat& img, std::string title = "Display Window"){
    cv::namedWindow( title, cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow(title, img);                   // Show our image inside it.
    cv::waitKey(0);
    cv::destroyAllWindows();
};

int main(){
    cv::Mat img_gray = cv::imread("images/Lenna.png", 0);
    cv::Mat img_rgb = cv::imread("images/Lenna.png");

    int x = 100, y = 200;
    
    //x is along left-right direction
    cv::circle(img_gray, cv::Point(x, y), 10, cv::Scalar(0), cv::FILLED);
    cv::circle(img_rgb, cv::Point(x, y), 10, cv::Scalar(0, 0, 255), cv::FILLED);

    Show(img_gray, "circle");
    Show(img_rgb, "circle");
}
