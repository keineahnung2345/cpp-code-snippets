#include <iostream>

#include <Eigen/Core>
#include <Eigen/Geometry>

// https://stackoverflow.com/questions/35145790/how-do-to-determine-axis-angle-from-rotation-matrix-using-eigen-libary

int main(int argc, char** argv) {
    Eigen::Vector3d axis;
    axis.setRandom().normalize();
    std::cout << axis << "\n\n";

    Eigen::Matrix3d mat;
    mat = Eigen::AngleAxisd(0.256, axis);

    Eigen::AngleAxisd newAngleAxis(mat);

    std::cout << newAngleAxis.angle() << "\n" << newAngleAxis.axis() << "\n\n";

    return 0;
}

/*
-0.846852
 0.107965
-0.520755

0.256
-0.846852
 0.107965
-0.520755
*/
