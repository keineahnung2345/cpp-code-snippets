#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/dnn/dnn.hpp> //cv::dnn::NMSBoxes
#include <opencv2/core/types.hpp> //cv::Rect, cv::Rect2d

//https://docs.opencv.org/3.4/d6/d0f/group__dnn.html#ga6e9e67e8d1d8b3a70b55ab9ea715e70d
//https://docs.opencv.org/3.4/d4/db9/samples_2dnn_2object_detection_8cpp-example.html#a43

int main(){
    std::ifstream infile;
    std::string line;
    std::vector<cv::Rect2d> boxes;
    std::vector<float> scores;
    float objectnessThreshold = 0.7f, nmsThreshold = 0.3f;

    infile.open ("boxes.txt", std::ifstream::in);
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        float left, top, right, bottom;
        if (!(iss >> left >> top >> right >> bottom)) { break; } // error

        boxes.push_back(cv::Rect2d(left, top, right-left, bottom-top));
    }
    infile.close();

    infile.open ("scores.txt", std::ifstream::in);
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        float score;
        if (!(iss >> score)) { break; } // error

        scores.push_back(score);
    }
    infile.close();

    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, scores, objectnessThreshold, nmsThreshold, indices);
    std::cout << indices.size() << "/" << scores.size() << std::endl;
    return 0;
}
