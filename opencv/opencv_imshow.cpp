#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

//https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/display_image.html

int main(){
    cv::Mat img = cv::imread("../Lenna.png", 0);
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow( "Display window", img);                   // Show our image inside it.
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
