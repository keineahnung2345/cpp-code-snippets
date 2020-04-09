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

cv::Mat HorizontalConcat(cv::Mat& img1, cv::Mat& img2){
    cv::Mat target;
    //assume img1 is always larger than or equal to img2 in height
    if(img2.rows < img1.rows){
        //padding for img2
        int padh = img1.rows - img2.rows;
        cv::Mat tmp(cv::Size(img1.rows, img2.cols), CV_8UC1, cv::Scalar(0));
        copyMakeBorder(img2, tmp, 0, padh, 0, 0, cv::BORDER_CONSTANT, cv::Scalar(0));
        img2 = tmp;
    }
    hconcat(img1, img2, target);

    return target;
};

int main(){
    cv::Mat img1 = cv::imread("images/Lenna.png", 0);
    int x = 20, y = 30, w = 400, h = 400;
    cv::Mat img2 = img1(cv::Rect(x, y, w, h));

    Show(img2, "cropped");
    cv::Mat result = HorizontalConcat(img1, img2);

    Show(result, "Horizontal Concat");
}
