#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp> //line
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/hal/interface.h> //CV_8UC3
#include <opencv2/highgui.hpp> //namedWindow
#include <iostream>
#include <map>

using namespace std;

//https://stackoverflow.com/questions/5050612/draw-histogram-of-a-colored-image-with-opencv
//https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html

bool GenHist(cv::Mat& img, vector<double>& pdHist, int n, bool normalize = true){
    //output is probability range from 0 to 1
    if(type2str(img.type()) != "8UC1") return false;
    if(n <= 0 || n > 256) return false;
    pdHist = vector<double>(n, 0);
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            int val = (int)img.at<uchar>(i, j);
            pdHist[(int)val * (n/256.0)]++;
        }
    }

    int pixelCount = img.rows * img.cols;

    if(normalize){
        for(int i = 0; i < pdHist.size(); i++){
            pdHist[i] /= (double)pixelCount;
        }
    }
    return true;
};

void ShowHist(vector<double>& hist){
    //output image size
    int img_w = 512; int img_h = 400;
    int bin_w = (int)((double)img_w/hist.size());

    cv::Mat histImage(img_h, img_w, CV_8UC3, cv::Scalar( 0,0,0));

    /// Normalize the result to [ 0, histImage.rows ]
    cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

    /// Draw for each channel
    for( int i = 1; i < hist.size(); i++ )
    {
        cv::line(histImage, cv::Point(bin_w*(i-1), img_h - hist[i-1]) ,
                        cv::Point(bin_w*(i), img_h - hist[i]),
                        cv::Scalar(255, 255, 255), 2, 8, 0);
    }

    cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow("Histogram", histImage);                   // Show our image inside it.
    cv::waitKey(0);
};

int main(){
    cv::Mat img = cv::imread("../Lenna.png", 0);
    
    vector<double> hist;
    cout << "Please input the bin count of histogram..." << endl;
    int n;
    cin >> n;
    GenHist(img, hist, n);
    ShowHist(hist);

    return 0;
}
