# PCL
The [Point Cloud Library (PCL)](https://github.com/PointCloudLibrary/pcl) is a standalone, large scale, open project for 2D/3D image and point cloud processing.

## install from source
Prerequisite: [boost](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/boost/README.md), [Eigen](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/Eigen/README.md), [flann](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/flann/README.md) and [VTK](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#vtk).
([Qhull](https://github.com/keineahnung2345/cpp-code-snippets/tree/master/qhull) is required if you want to use `pcl_surface`.)

First download `pcl-pcl-1.8.1.tar.gz`(or other newer versions) from [pcl release page](https://github.com/PointCloudLibrary/pcl/releases), and then untar it.

Then:
```sh
cd pcl-pcl-1.8.1 && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. #or use "ccmake .." to choose what to build
make -j2
sudo make -j2 install
```

After installation, there will be many executable files in `/usr/local/bin`, and `pcl_viewer` is one of them which is useful.

### Troubleshooting

```
pcl-pcl-1.8.1/visualization/include/pcl/visualization/impl/pcl_visualizer.hpp:603:24: error: ‘class vtkMapper’ has no member named ‘ImmediateModeRenderingOn’
pcl-pcl-1.8.1/visualization/src/pcl_visualizer.cpp:1149:13: error: ‘class vtkDataSetMapper’ has no member named ‘ImmediateModeRenderingOff’
pcl-pcl-1.8.1/visualization/src/pcl_visualizer.cpp:1475:28: error: ‘class vtkMapper’ has no member named ‘SetImmediateModeRendering’
pcl-pcl-1.8.1/visualization/src/pcl_visualizer.cpp:3336:16: error: invalid use of incomplete type ‘class vtkTexture’
pcl-pcl-1.8.1/visualization/src/pcl_visualizer.cpp:3336:34: error: incomplete type ‘vtkTexture’ used in nested name specifier
vtk-8.2/vtkSmartPointer.h:113:40: error: invalid static_cast from type ‘vtkObjectBase* const’ to type ‘vtkTexture*’
```

According to [Error building pcl::visualization](https://github.com/PointCloudLibrary/pcl/issues/2155) and [编译pcl1.9.1中出现error: ‘class vtkDataSetMapper’ has no member named ‘ImmediateModeRenderingOff‘问题的解决方法](https://blog.csdn.net/l1216766050/article/details/91346776), it can be solved by update PCL version(like 1.10.1).

## install through apt
[PCL Downloads](https://pointclouds.org/downloads/#linux)
```sh
sudo apt install libpcl-dev
```

## use it in another project

Reference to [Using PCL in your own project](https://pcl-tutorials.readthedocs.io/en/latest/using_pcl_pcl_config.html):

```
set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(MY_GRAND_PROJECT)
# specify the components required
#find_package(PCL 1.10 REQUIRED COMPONENTS common io)
# or use all available components
find_package(PCL 1.10 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(<NAME> <NAME>.cpp)
target_link_libraries(<NAME> ${PCL_LIBRARIES})
```
