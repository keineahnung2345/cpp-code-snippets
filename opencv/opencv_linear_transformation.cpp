#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <sstream>

//g++ BasicLinearTransforms.cpp `pkg-config --cflags --libs opencv` -std=c++11

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{   
    std::ostringstream out;
    out.precision(n); 
    out << std::fixed << a_value;
    return out.str();
}

using namespace cv;
double alpha; /*< Simple contrast control */
int beta;  /*< Simple brightness control */
int main( int argc, char** argv )
{
    Mat image = imread( argv[1] );
    Mat new_image = Mat::zeros( image.size(), image.type() );
    std::cout<<" Basic Linear Transforms "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    //std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
    //std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;
    double alphas[] = {1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4};
    double betas[] = {0}; //, -10, -20, -30, -40, -50, -60, -70, -80, -90, -100};
    for(double alpha : alphas){
        for(double beta : betas){
            image.convertTo(new_image, -1, alpha, beta);
            imwrite("images/org.jpg", image);
            imwrite("images/"+to_string_with_precision(alpha, 1)+"_"+to_string_with_precision(beta,0)+".jpg", new_image);
        }
    }
    /*
    for( int y = 0; y < image.rows; y++ ) {
        for( int x = 0; x < image.cols; x++ ) {
            for( int c = 0; c < 3; c++ ) {
                new_image.at<Vec3b>(y,x)[c] =
                saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }
    */
    return 0;
}
