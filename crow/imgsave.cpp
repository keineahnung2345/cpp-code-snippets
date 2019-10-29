#include "crow_all.h"
#include "base64.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <utility>
#include <opencv2/core/mat.hpp> //cv::Mat
#include <opencv2/imgcodecs.hpp> //cv::IMREAD_UNCHANGED
#include <opencv2/imgproc.hpp> //cv::cvtColor, uchar?

using namespace std;

//compile with:
//export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<boost_installation_dir>/lib
//g++ imgsave.cpp <cpp-base64_installation_dir>/base64.cpp -I <crow_dir>/amalgamate/ -I <cpp-base64_installation_dir> -L <boost_installation_dir>/lib/ -lboost_system `pkg-config --cflags --libs opencv4` -lpthread -std=c++11
//note that imgsave.cpp and base64.cpp should be compiled together(g++ with 2 or more cpp is just like add_executable with 2 or more cpp)

//this service parse the request and save the image from request

int main(int argc, char* argv[]) {
// crow app
    crow::SimpleApp app;
    CROW_ROUTE(app, "/imgsave").methods("POST"_method)
    //CROW_ROUTE(app, "/test").methods(crow::HTTPMethod::Post)
    ([](const crow::request& req){
        crow::json::wvalue result;
        result["flag"] = 0;
        result["errorMsg"] = "";
        std::ostringstream os;
        try {
            auto info = crow::json::load(req.body);
            CROW_LOG_INFO << "parsing info...";
            if(!info) CROW_LOG_INFO << "bad request";
            CROW_LOG_INFO << "info has img?" << info.has("img");
            string base64_string = info["img"].s();
            // read in base 64 string
            CROW_LOG_INFO << "img string length: " << base64_string.size();
            string decoded_image = base64_decode(base64_string);
            vector<uchar> data(decoded_image.begin(), decoded_image.end());
            cv::Mat frame = imdecode(data, cv::IMREAD_UNCHANGED);
            //cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
            //CROW_LOG_INFO << "convert color successfully.";
            cv::imwrite("abc.jpg", frame);
            result["flag"] = 1;
            os << crow::json::dump(result);
            return crow::response{os.str()};
        }
        catch (exception& e){
            CROW_LOG_INFO << "Unpredicted error: " << e.what();
            result["errorMsg"] = "Unknowm Error";
            os << crow::json::dump(result);
            return crow::response(os.str());
        }
    });
    app.port(8181).run();
    return 0;
}
