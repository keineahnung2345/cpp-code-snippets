#include <vector>
#include <iostream>

#include <Eigen/Dense>

using namespace std;

int main(int argc, char** argv) {
    Eigen::Vector3f mat(1.2, 3.4, 5.6);
    vector<float> vec(mat.data(), mat.data() + mat.size());
    for (const float& e : vec) {
        cout << e << " ";
    }
    cout << endl;
    //1.2 3.4 5.6

    return 0;
}
