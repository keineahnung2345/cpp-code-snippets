#include <vector>
#include <iostream>

#include <Eigen/Dense>
#include <Eigen/Core> //Eigen::Map

//https://stackoverflow.com/questions/26094379/typecasting-eigenvectorxd-to-stdvector
//https://stackoverflow.com/questions/17036818/initialise-eigenvector-with-stdvector

using namespace std;

Eigen::VectorXf stdToEigenVector(const std::vector<float>& vec) {
    return Eigen::Map<Eigen::VectorXf, Eigen::Unaligned>(
        const_cast<float*>(vec.data()), vec.size());
}

Eigen::VectorXd stdToEigenVector(const std::vector<double>& vec) {
    return Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(
        const_cast<double*>(vec.data()), vec.size());
}

std::vector<float> eigenToStdVector(const Eigen::VectorXf& vec) {
    return std::vector<float>(vec.data(), vec.data() + vec.size());
}

std::vector<double> eigenToStdVector(const Eigen::VectorXd& vec) {
    return std::vector<double>(vec.data(), vec.data() + vec.size());
}

int main(int argc, char** argv) {
    Eigen::Vector3f mat(1.2, 3.4, 5.6);
    vector<float> vec = eigenToStdVector(mat);
    for (float& e : vec) {
        cout << e << " ";
        e += 1;
    }
    cout << endl;
    //1.2 3.4 5.6
    
    mat = stdToEigenVector(vec);
    for (size_t i = 0; i < 3; ++i){
        cout << mat(i) << " ";
    }
    cout << endl;

    return 0;
}
