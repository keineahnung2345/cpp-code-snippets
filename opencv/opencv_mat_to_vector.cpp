#include <opencv2/opencv.hpp>
#include <vector>

//g++ mat_to_vec.cpp `pkg-config --cflags --libs opencv`
//https://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html#howtoscanimagesopencv

template <typename T>
void mat2vec(cv::Mat& I, std::vector<T>& v){
    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    T* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<T>(i);
        for ( j = 0; j < nCols; ++j)
        {
            v.push_back(p[j]);
        }
    }
}

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

void output_info(cv::Mat& m){
    std::cout << "size: " << m.size << " x " << m.channels() << std::endl;
    std::cout << "data type: " << type2str(m.type()) << std::endl;
}

int main(){
    cv::Mat img = cv::imread("xxx.jpeg");
    output_info(img);

    std::vector<uchar> v;
    mat2vec(img, v);
    std::cout << v.size() << std::endl;

    cv::Mat float_img;
    img.convertTo(float_img, CV_32F);
    output_info(float_img);

    //test mat2vec with different data type
    std::vector<float> vf;
    mat2vec(float_img, vf);
    std::cout << vf.size() << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << (float)v[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << vf[i] << " ";
    }
    std::cout << std::endl;
}

/**
size: 173 x 292 x 3
data type: 8UC3
151548
size: 173 x 292 x 3
data type: 32FC3
151548
203 212 226 203 212 226 203 212 226 204 
203 212 226 203 212 226 203 212 226 204
**/
