//https://stackoverflow.com/questions/24764031/cast-eigenmatrixxd-to-eigenmatrixxf
#include <Eigen/Core>
#include <iostream>

using namespace std;

int main() {
    Eigen::Matrix3d mat_d;
    mat_d << 1, 2, 3,
             4, 5, 6,
             7, 8, 9;
    Eigen::Matrix3f mat_f = mat_d.cast<float>();

    cout << mat_d << endl;
    cout << mat_f << endl;

    Eigen::Vector3f vec_f;
    vec_f << 1, 2, 3;
    Eigen::Vector3d vec_d = vec_f.cast<double>();

    cout << vec_f << endl;
    cout << vec_d << endl;
    return 0;
}

/*
1 2 3
4 5 6
7 8 9
1 2 3
4 5 6
7 8 9
1
2
3
1
2
3
*/
