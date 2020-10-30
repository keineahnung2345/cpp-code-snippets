#include <opencv2/opencv.hpp>

//g++ opencv_split_channels.cpp `pkg-config --cflags --libs opencv`
//https://stackoverflow.com/questions/6699374/access-to-each-separate-channel-in-opencv
//https://stackoverflow.com/questions/23768832/how-to-copy-grayscale-image-to-rgb-images-red-channel-in-opencv

int main(){
    cv::Mat img = cv::imread("xxx.jpeg");
    std::cout << "image size: " << img.size << ", channels: " << img.channels() << std::endl;
    cv::Mat ch1, ch2, ch3;
    // "channels" is a vector of 3 Mat arrays:
    std::vector<cv::Mat> channels(3);
    // split img:
    cv::split(img, channels);
    // get the channels (dont forget they follow BGR order in OpenCV)
    ch1 = channels[0];
    ch2 = channels[1];
    ch3 = channels[2];
    std::cout << "after split, one channel's size: " << ch1.size << ", channels: " << ch1.channels() << std::endl;
    
    cv::Mat color;
    cv::merge(channels, color);
}

//image size: 173 x 292, channels: 3
//after split, one channel's size: 173 x 292, channels: 1
