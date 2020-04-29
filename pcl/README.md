# PCL
The [Point Cloud Library (PCL)](https://github.com/PointCloudLibrary/pcl) is a standalone, large scale, open project for 2D/3D image and point cloud processing.

## Installation
Prerequisite: [boost](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/boost/README.md), [Eigen](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/Eigen/README.md), [flann](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/flann/README.md) and [VTK](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#vtk).

First download `pcl-pcl-1.8.1.tar.gz`(or other newer versions) from [pcl release page](https://github.com/PointCloudLibrary/pcl/releases), and then untar it.

Then:
```sh
cd pcl-pcl-1.8.1 && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j2
sudo make -j2 install
```
