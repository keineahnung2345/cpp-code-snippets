# OpenCV

## Installation
[linux-commands/Linux packages - opencv](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#opencv)

Or install it through `apt`:
```sh
sudo apt install libopencv-dev
```
On Ubuntu 20.04, it will install OpenCV 4.2.0.

Its installation path will be `/usr/include/opencv4`.

## Check version
Check the file `<opencv_root_dir>/include/opencv2/core/version.hpp`:
```cpp
#define CV_VERSION_MAJOR    4
#define CV_VERSION_MINOR    1
#define CV_VERSION_REVISION 2
#define CV_VERSION_STATUS   "-openvino"
```

or according to [Find OpenCV Version Installed on Ubuntu [duplicate]](https://stackoverflow.com/questions/8804064/find-opencv-version-installed-on-ubuntu/12536170):

```sh
pkg-config --modversion opencv
```

if it's installed through `apt`, you can use the binary file:
```sh
/usr/bin/opencv_version #4.2.0
```

## g++
compile, including opencv headers and libraries
[compiling opencv in c++](https://stackoverflow.com/questions/9094941/compiling-opencv-in-c)
```sh
g++ xxx.cpp `pkg-config --cflags --libs opencv`
```
or:
```sh
g++ xxx.cpp `pkg-config --cflags --libs opencv4` -std=c++11
```
for OpenCV4.

If the above fails, use the following:
```sh
g++ xxx.cpp -I /usr/local/include/opencv4 -L /usr/local/lib -lopencv_imgcodecs -lopencv_core -lopencv_imgproc -lopencv_highgui -std=c++11
```

`opencv_imgproc` is for drawing lines, circles, ...

`opencv_highgui` is for generating GUI.

In `xxx.cpp`, it includes `opencv2/imgcodecs.hpp`, so we need to link with `opencv_imgcodecs`.
We also need to link `opencv_core` because otherwise it gives the following error:
```
/usr/bin/ld: /tmp/cc7ZradY.o: undefined reference to symbol '_ZN2cv8fastFreeEPv'
//usr/local/lib/libopencv_core.so.4.1: error adding symbols: DSO missing from command line
collect2: error: ld returned 1 exit status
```

## cmake
### use OpenCV after installing
To use OpenCV, add the following in `CMakeLists.txt`:
```cmake
set(OpenCV_DIR /usr/local/lib)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBRARIES}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
add_definitions(-DOPENCV)
add_executable(<exeutable_file_name> <./src/xxx.cpp>)
# ${OpenCV_LIBS} is set by "FIND_PACKAGE"
target_link_libraries(<exeutable_file_name>  ${OpenCV_LIBS})
```
To find OpenCV installation directory, use the following instruction and pick a suitable one:
```sh
find / -name OpenCVConfig.cmake
```

### use OpenCV without installing
To use OpenCV without installing, we need to:
1. copy all `/usr/local/lib/libopencv*.so.4.1.2` into `${CMAKE_SOURCE_DIR}/libs`
2. make softlinks: libopencv_photo.so -> libopencv_photo.so.4.1.2 and libopencv_photo.so.4.1 -> libopencv_photo.so.4.1.2
3. copy `/usr/local/include/opencv4/opencv2` into `${PROJECT_SOURCE_DIR}/include`

And then add the following in `CMakeLists.txt`:
```cmake
# ${CMAKE_SOURCE_DIR} is the directory containing CMakeLists.txt
link_directories(${CMAKE_SOURCE_DIR}/libs)
set(OpenCV_LIBS "opencv_photo;opencv_videoio;opencv_imgcodecs;opencv_imgproc;opencv_dnn;opencv_calib3d;opencv_stitching;opencv_core;opencv_features2d;opencv_ml;opencv_video;opencv_flann;opencv_objdetect;opencv_highgui;opencv_gapi;opencv_superres;opencv_img_hash;opencv_bgsegm;opencv_line_descriptor;opencv_tracking;opencv_datasets;opencv_xobjdetect;opencv_face;opencv_quality;opencv_hdf;opencv_text;opencv_bioinspired;opencv_xfeatures2d;opencv_xphoto;opencv_rgbd;opencv_ximgproc;opencv_surface_matching;opencv_fuzzy;opencv_stereo;opencv_freetype;opencv_dnn_objdetect;opencv_shape;opencv_reg;opencv_hfs;opencv_videostab;opencv_saliency;opencv_dpm;opencv_structured_light;opencv_optflow;opencv_dnn_superres;opencv_aruco;opencv_sfm;opencv_plot;opencv_phase_unwrapping;opencv_ccalib")
# message("OpenCV_LIBS" "${OpenCV_LIBS}")
# should copy /usr/local/lib/libopencv_photo.so.4.1.2(and all other opencv libs) to "${CMAKE_SOURCE_DIR}/libs"
# and make softlinks libopencv_photo.so -> libopencv_photo.so.4.1.2 and libopencv_photo.so.4.1 -> libopencv_photo.so.4.1.2
add_executable(<exeutable_file_name> <./src/xxx.cpp>)
target_link_libraries(<exeutable_file_name>  ${OpenCV_LIBS})
# should copy /usr/local/include/opencv4/opencv2 into ${PROJECT_SOURCE_DIR}/include
target_include_directories(<exeutable_file_name> PUBLIC ${PROJECT_SOURCE_DIR}/include)
```

Ref: [CMake link to external library](https://stackoverflow.com/questions/8774593/cmake-link-to-external-library)
