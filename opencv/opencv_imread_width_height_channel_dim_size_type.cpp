#include <iostream>
#include "opencv2/opencv.hpp"

//https://stackoverflow.com/questions/32971241/how-to-get-image-width-and-height-in-opencv/32971309
//https://stackoverflow.com/questions/17363886/can-i-determine-the-number-of-channels-in-cvmat-opencv
//https://stackoverflow.com/questions/10167534/how-to-find-out-what-type-of-a-mat-object-is-with-mattype-in-opencv
//https://stackoverflow.com/questions/13428689/whats-the-difference-between-cvtype-values-in-opencv
//CV_8U=0, CV_8S=1, CV_16U=2, CV_16S=3, CV_32S=4, CV_32F=5, CV_64F=6

std::string type2str(int type) {
  std::string r;
  
  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);
  
  switch ( depth ) { 
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }
  
  r += "C";
  r += (chans+'0');
  
  return r;
}

int main()
{
    cv::Mat src = cv::imread("../Lenna.png");
    std::cout << "Read as RGB" << std::endl;
    std::cout << "Width : " << src.cols << std::endl;
    std::cout << "Height: " << src.rows << std::endl;
    std::cout << "size: " << src.size << std::endl;
    std::cout << "dimension: " << src.dims << std::endl;
    std::cout << "channels: " << src.channels() << std::endl;
    std::cout << "type: " << type2str(src.type()) << std::endl; 
    std::cout << std::endl;

    src = cv::imread("../Lenna.png", 0);
    std::cout << "Read as grayscale" << std::endl;
    std::cout << "Width : " << src.cols << std::endl;
    std::cout << "Height: " << src.rows << std::endl;
    std::cout << "size: " << src.size << std::endl;
    std::cout << "dimension: " << src.dims << std::endl;
    std::cout << "channels: " << src.channels() << std::endl;
    std::cout << "type: " << type2str(src.type()) << std::endl; 

   return 0;
}
