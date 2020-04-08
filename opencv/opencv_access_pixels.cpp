#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(){
    cv::Mat img = cv::imread("../Lenna.png", 0);
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            cout << (int)img.at<uchar>(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
