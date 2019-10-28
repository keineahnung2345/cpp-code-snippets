#include "cpr/cpr.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <opencv2/core/mat.hpp> //cv::Mat
#include <opencv2/imgcodecs.hpp> //cv::IMREAD_UNCHANGED
#include <opencv2/imgproc.hpp> //cv::cvtColor, uchar?
#include "base64.h"

int main(){
    nlohmann::json req_body;
    cv::Mat img = cv::imread("face.jpeg");
    std::vector<uchar> data_encode;
    cv::imencode(".jpg", img, data_encode);
    uchar* data_encode_arr= data_encode.data();
    std::string str_encode = base64_encode(data_encode_arr, data_encode.size());
    req_body["img"] = str_encode;
    auto response = cpr::Post(cpr::Url{"http://0.0.0.0:8181/imgsave"},
                            cpr::Body{req_body.dump()},
                            cpr::Header{{"Content-Type", "application/json"}});
    if(response.status_code == 200){
        std::cout << "Parse response..." << std::endl;
        auto result = nlohmann::json::parse(response.text);
        std::cout << result["flag"] << std::endl;
        std::cout << result["errorMsg"] << std::endl;
    }
    return 0;
}
