#include <iostream>
#include "opencv2/opencv.hpp"

//https://docs.opencv.org/2.4/modules/core/doc/drawing_functions.html#void%20putText(Mat&%20img,%20const%20string&%20text,%20Point%20org,%20int%20fontFace,%20double%20fontScale,%20Scalar%20color,%20int%20thickness,%20int%20lineType,%20bool%20bottomLeftOrigin)
//https://stackoverflow.com/questions/46500066/how-to-put-a-text-in-an-image-in-opencv-c/46500123

int main()
{
    cv::Mat img = cv::imread("face.jpeg");
    std::string text = "hello";
    cv::Point pt = cv::Point(50, 50);
    int fontFace = cv::FONT_HERSHEY_DUPLEX;
    double fontScale = 1.0;
    cv::Scalar color = CV_RGB(118, 185, 0);
    int thickness = 2;
    cv::putText(img, text, pt, fontFace, fontScale, color, thickness);
    cv::imwrite("face_text.jpeg", img);
    return 0;
}
