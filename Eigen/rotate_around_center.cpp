#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

// https://stackoverflow.com/questions/38274455/eigen-perform-an-3d-rotation-around-an-axis-w-and-anchored-at-a-point-p
// https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
// https://stackoverflow.com/questions/6563810/m-pi-works-with-math-h-but-not-with-cmath-in-visual-studio

int main(int argc, char** argv) {
    Eigen::Vector3f point(0, 0, 1);
    Eigen::Vector3f axis(1, 0, 0);
    float           theta = 90.0f / 180.0f * M_PI;
    Eigen::Vector3f rotation_center(0, 1, 0);
    Eigen::Affine3f affine = Eigen::Translation3f(rotation_center) *
                             Eigen::AngleAxisf(theta, axis) *
                             Eigen::Translation3f(-rotation_center);
    std::cout << "original point: " << point << std::endl;
    std::cout << "rotated point: " << affine * point << std::endl;

    return 0;
}

/*
original point: 0
0
1
rotated point:  0
 0
-1
*/
