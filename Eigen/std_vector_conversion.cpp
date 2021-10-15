#include <vector>
#include <iostream>

#include <Eigen/Dense>
#include <Eigen/Core> //Eigen::Map

//https://stackoverflow.com/questions/26094379/typecasting-eigenvectorxd-to-stdvector
//https://stackoverflow.com/questions/17036818/initialise-eigenvector-with-stdvector

using namespace std;

int main(int argc, char** argv) {
    Eigen::Vector3f mat(1.2, 3.4, 5.6);
    vector<float> vec(mat.data(), mat.data() + mat.size());
    for (float& e : vec) {
        cout << e << " ";
        e += 1;
    }
    cout << endl;
    //1.2 3.4 5.6
    
    mat = Eigen::Map<Eigen::Vector3f, Eigen::Unaligned>(vec.data(), vec.size());
    for (size_t i = 0; i < 3; ++i){
        cout << mat(i) << " ";
    }
    cout << endl;

    return 0;
}
