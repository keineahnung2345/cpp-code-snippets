#include <vector>
#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/15783010/c-template-double-stdcomplexdouble-norm-and-product

template <typename T>
double getNorm(vector<vector<T>>& vv, int row, int col){};

template <typename T>
double getNorm(vector<vector<T>>& vv, int row, int col);

template<>
inline double getNorm(vector<vector<double>>& vv, int row, int col) { return vv[row][col]; }

template <>
inline double getNorm(vector<vector<complex<double>>>& vv, int row, int col) { return sqrt(pow(vv[row][col].real(), 2) + pow(vv[row][col].imag(), 2)); }

int main(){
    vector<vector<double>> vvd(3, vector<double>(3, 0.0));
    vector<vector<complex<double>>> vvc(3, vector<complex<double>>(3, complex<double>(0.0, 0.0)));

    cout << getNorm(vvd, 0, 0) << endl;
    cout << getNorm(vvc, 0, 0) << endl;
}
