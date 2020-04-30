# PCL
The [Point Cloud Library (PCL)](https://github.com/PointCloudLibrary/pcl) is a standalone, large scale, open project for 2D/3D image and point cloud processing.

## Installation
Prerequisite: [boost](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/boost/README.md), [Eigen](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/Eigen/README.md), [flann](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/flann/README.md) and [VTK](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#vtk).

First download `pcl-pcl-1.8.1.tar.gz`(or other newer versions) from [pcl release page](https://github.com/PointCloudLibrary/pcl/releases), and then untar it.

Then:
```sh
cd pcl-pcl-1.8.1 && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. #or use "ccmake .." to choose what to build
make -j2
sudo make -j2 install
```

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
