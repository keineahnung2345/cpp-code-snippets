#include "base64.h"
#include <opencv2/imgcodecs.hpp> //imread
#include <iostream>

int main() {
    cv::Mat img = cv::imread("face.jpeg");
    std::vector<uchar> data_encode;
    cv::imencode(".jpg", img, data_encode);
    uchar* data_encode_arr= data_encode.data();
    std::string str_encode = base64_encode(data_encode_arr, data_encode.size());
    std::cout << "encode into: " << str_encode << std::endl;
    std::string str_decode = base64_decode(str_encode);
    //std::cout << "decode into: " << str_decode << std::endl;
    std::string str_decode_encode = base64_encode(reinterpret_cast<const unsigned char*>(str_decode.c_str()), str_decode.length());
    std::cout << "decode and then encode: " << str_decode_encode << std::endl;
    return 0;
}
