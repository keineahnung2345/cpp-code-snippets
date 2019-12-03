#include <iostream>
#include <opencv2/core/types.hpp> //cv::Rect, cv::Rect2f

int main(){
    float x = 0.1f, y = 0.3f, width = 0.5f, height = 0.1f;
    cv::Rect r = cv::Rect(x, y, width, height);
    cv::Rect2f rf = cv::Rect2f(x, y, width, height);
    std::cout << r.x << ", " << r.y << ", "  << r.width << ", " << r.height << std::endl;
    //0, 0, 0, 0
    std::cout << rf.x << ", " << rf.y << ", "  << rf.width << ", " << rf.height << std::endl;
    //0.1, 0.3, 0.5, 0.1
    return 0;
}
