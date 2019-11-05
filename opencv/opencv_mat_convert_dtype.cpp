#include <opencv2/opencv.hpp>

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

//https://stackoverflow.com/questions/3188352/changing-the-dataype-of-a-mat-class-instance-in-opencv-c-interface
//g++ convert_dtype.cpp `pkg-config --cflags --libs opencv`

int main(){
    cv::Mat m_uchar = cv::imread("face.jpeg");
    cv::Mat m_float, m_double;

    m_uchar.convertTo(m_float, CV_32F);
    m_uchar.convertTo(m_double, CV_64F);

    std::cout << type2str(m_uchar.type()) << std::endl;
    std::cout << type2str(m_float.type()) << std::endl;
    std::cout << type2str(m_double.type()) << std::endl;
    return 0;
}
