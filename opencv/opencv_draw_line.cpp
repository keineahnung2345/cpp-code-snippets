#include <opencv2/imgproc.hpp> //line
#include <opencv2/imgcodecs.hpp> //imread, imwrite

int main(){
    cv::Mat img = cv::imread("face.jpeg");
    cv::Point p1 = cv::Point(0,0), p2 = cv::Point(50,50);
    const cv::Scalar blue = cv::Scalar(255, 0, 0);
    const int thickness = 2;
    cv::line(img, p1, p2, blue, thickness);
    cv::imwrite("line.jpg", img);
    return 0;
}
