#include <opencv2/opencv.hpp>

//https://stackoverflow.com/questions/43183931/opencv-create-3-channel-mat-from-continuous-data-array
//https://stackoverflow.com/questions/4504687/cycle-through-pixels-with-opencv

//cv::Mat createMat(uchar *rawData, unsigned int dimX, unsigned int dimY)
cv::Mat createMat(float *rawData, unsigned int dimX, unsigned int dimY)
{   
    // No need to allocate outputMat here
    cv::Mat outputMat;
    
    // Build headers on your raw data
    int cv_channel_const;
    //cv_channel_const = CV_8UC1;
    cv_channel_const = CV_32FC1;
    
    cv::Mat channelR(dimY, dimX, cv_channel_const, rawData); 
    cv::Mat channelG(dimY, dimX, cv_channel_const, rawData + dimX * dimY);
    cv::Mat channelB(dimY, dimX, cv_channel_const, rawData + 2 * dimX * dimY);
    
    // Invert channels, 
    // don't copy data, just the matrix headers
    //std::vector<cv::Mat> channels = { channelB, channelG, channelR };
    std::vector<cv::Mat> channels = { channelR, channelG, channelB };
    
    // Create the output matrix
    merge(channels, outputMat);
    
    return outputMat;
}

int main(){
    float data[] =
                   {1,2,3, 4,5,6, 7,8,9,
                    11,12,13, 14,15,16, 17,18,19,
                    21,22,23, 24,25,26, 27,28,29};

    cv::Mat mat = createMat(data, 3, 3);
    std::cout << mat.size() << " x " << mat.channels() << std::endl;
    for(int c = 0; c < mat.channels(); c++){
        for(int i = 0; i < mat.rows; i++){
            for(int j = 0; j < mat.cols; j++){
                //cv::Vec3f should become cv::Vec3b if the array's type is uchar
                std::cout << mat.at<cv::Vec3f>(i,j)[c] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
