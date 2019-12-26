#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

//https://www.learnopencv.com/how-to-find-opencv-version-python-cpp/
//g++ cv_version.cpp -I /opt/intel/openvino/opencv/include/ -L /opt/intel/openvino/opencv/lib/ -std=c++11

int main( int argc, char** argv )
{
  cout << "OpenCV version : " << CV_VERSION << endl;
  cout << "Major version : " << CV_MAJOR_VERSION << endl;
  cout << "Minor version : " << CV_MINOR_VERSION << endl;
  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
}
