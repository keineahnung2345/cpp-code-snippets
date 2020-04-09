#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

//https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/display_image.html

void Show(cv::Mat& img, std::string title = "Display Window"){
    cv::namedWindow( title, cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow(title, img);                   // Show our image inside it.
    cv::waitKey(0);
    cv::destroyAllWindows();
};

int main(){
    cv::Mat img = cv::imread("../Lenna.png", 0);
    Show(img, "Lenna");
    return 0;
}
