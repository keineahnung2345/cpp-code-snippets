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
    cv::Mat img = cv::imread("images/Lenna.png", 0);
    int w = 100, h = 50;
    //width first!
    resize(img, img, cv::Size(w, h), 0, 0, cv::INTER_LINEAR);

    Show(img, "resized");
}
