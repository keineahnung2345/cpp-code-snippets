# ceres

## install dependencies
```sh
sudo apt install libgoogle-glog-dev libgflags-dev -y
sudo apt install libatlas-base-dev -y
sudo apt install libsuitesparse-dev -y
```

## install from source
```sh
git clone https://ceres-solver.googlesource.com/ceres-solver
cd ceres-solver/
mkdir build
cd build/
cmake ..
make -j8
make test
sudo make install
```

## test
```sh
bin/simple_bundle_adjuster ../data/problem-16-22106-pre.txt
```
Output:
```
iter      cost      cost_change  |gradient|   |step|    tr_ratio  tr_radius  ls_iter  iter_time  total_time
   0  4.185660e+06    0.00e+00    1.09e+08   0.00e+00   0.00e+00  1.00e+04        0    7.52e-02    2.06e-01
   1  1.062590e+05    4.08e+06    8.99e+06   5.36e+02   9.82e-01  3.00e+04        1    1.36e-01    3.42e-01
   2  4.992817e+04    5.63e+04    8.32e+06   3.19e+02   6.52e-01  3.09e+04        1    1.30e-01    4.72e-01
   3  1.899774e+04    3.09e+04    1.60e+06   1.24e+02   9.77e-01  9.26e+04        1    1.29e-01    6.02e-01
   4  1.808729e+04    9.10e+02    3.97e+05   6.39e+01   9.51e-01  2.78e+05        1    1.29e-01    7.31e-01
   5  1.803399e+04    5.33e+01    1.48e+04   1.23e+01   9.99e-01  8.33e+05        1    1.29e-01    8.61e-01
   6  1.803390e+04    9.02e-02    6.35e+01   8.00e-01   1.00e+00  2.50e+06        1    1.28e-01    9.89e-01

Solver Summary (v 2.0.0-eigen-(3.3.7)-lapack-suitesparse-(5.7.1)-cxsparse-(3.2.0)-eigensparse-no_openmp)

                                     Original                  Reduced
Parameter blocks                        22122                    22122
Parameters                              66462                    66462
Residual blocks                         83718                    83718
Residuals                              167436                   167436

Minimizer                        TRUST_REGION

Dense linear algebra library            EIGEN
Trust region strategy     LEVENBERG_MARQUARDT

                                        Given                     Used
Linear solver                     DENSE_SCHUR              DENSE_SCHUR
Threads                                     1                        1
Linear solver ordering              AUTOMATIC                 22106,16
Schur structure                         2,3,9                    2,3,9

Cost:
Initial                          4.185660e+06
Final                            1.803390e+04
Change                           4.167626e+06

Minimizer iterations                        7
Successful steps                            7
Unsuccessful steps                          0

Time (in seconds):
Preprocessor                         0.130726

  Residual only evaluation           0.092829 (7)
  Jacobian & residual evaluation     0.389659 (7)
  Linear solver                      0.346584 (7)
Minimizer                            0.929677

Postprocessor                        0.003877
Total                                1.064283

Termination:                      CONVERGENCE (Function tolerance reached. |cost_change|/cost: 1.769764e-09 <= 1.000000e-06)
```
