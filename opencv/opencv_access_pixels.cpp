#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/17919399/accessing-pixel-value-of-gray-scale-image-in-opencv
//https://stackoverflow.com/questions/8932893/accessing-certain-pixel-rgb-value-in-opencv

int main(){
    cv::Mat img_gray = cv::imread("images/Lenna.png", 0);
    cv::Mat img_bgr = cv::imread("images/Lenna.png");

    //for gray image
    for(int i = 0; i < img_gray.rows; i++){
        for(int j = 0; j < img_gray.cols; j++){
            cout << (int)img_gray.at<uchar>(i, j) << " ";
            break;
        }
        cout << endl;
        break;
    }
    
    //for colored image
    for(int i = 0; i < img_bgr.rows; i++){
        for(int j = 0; j < img_bgr.cols; j++){
            for(int c = 0; c < 3; c++){
                cout << (int)img_bgr.at<cv::Vec3b>(i, j)[c] << " ";
            }
            break;
        }
        cout << endl;
        break;
    }

    return 0;
}
