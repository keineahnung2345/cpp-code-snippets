# Eigen
[Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html) is a C++ template library for linear algebra.

## install from source
According to [How to install eigen 3.3 in Ubuntu 14.04?](https://askubuntu.com/questions/860207/how-to-install-eigen-3-3-in-ubuntu-14-04), Eigen is a header-only library, so we don't have to "install" it.

First download `eigen-3.3.4.tar.gz`(or other newer versions) from its [gitlab repo](https://gitlab.com/libeigen/eigen/-/tree/3.3.4), and then untar it.

Symlink the Eigen folder into `/usr/local/include`:

```sh
ln -s /xxx/eigen-3.3.4/Eigen /usr/local/include/Eigen
```

Also:

```sh
ln -s /xxx/eigen-3.3.4/unsupported/ /usr/local/include/unsupported
```
otherwise when we `make` `pcl`, it will shows `fatal error: unsupported/Eigen/NonLinearOptimization: No such file or directory`.

Note that the arguments of `ln -s` must be full links, otherwise the target will be invalid.

## install through apt
```sh
apt install libeigen3-dev #get 3.3.7-2 in Ubuntu 20.04
```

## use it in another project

```cmake
cmake_minimum_required(VERSION 3.0)
project(MY_GRAND_PROJECT)

include_directories("/usr/include/eigen3")

add_executable(...)
target_link_libraries(...) 
```

## check version
[How to check the version number of Eigen C++ template library?](https://stackoverflow.com/questions/21497064/how-to-check-the-version-number-of-eigen-c-template-library)

Open `$(eigen_installation_dir)/eigen3/Eigen/src/Core/util/Macros.h` and find `EIGEN_WORLD_VERSION`, `EIGEN_MAJOR_VERSION`, `EIGEN_MINOR_VERSION` like:

```cpp
#define EIGEN_WORLD_VERSION 3
#define EIGEN_MAJOR_VERSION 3
#define EIGEN_MINOR_VERSION 7
```

Note: PCL 1.11.1 uses Eigen 3.3.7, PCL 1.12.1 uses Eigen 3.4.0
