#include <iostream>
#include <Eigen/Dense>

//https://stackoverflow.com/questions/51640997/how-to-get-the-number-of-rows-and-columns-of-an-eigenmatrixxd

int main() {
    Eigen::MatrixXd matrix(3, 4);

    int r = matrix.rows();
    int c = matrix.cols();

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


/*
1.02391e-311 0 1.02391e-311 6.95277e-310
1.02391e-311 1.62054e-319 1.02391e-311 0
9.15803e-313 9.15803e-313 1.02391e-311 1.02391e-311
*/
