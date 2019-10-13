# OpenCV

## g++
compile, including opencv headers and libraries
[compiling opencv in c++](https://stackoverflow.com/questions/9094941/compiling-opencv-in-c)
```sh
g++ xxx.cpp `pkg-config --cflags --libs opencv`
```

## cmake
To use OpenCV, add the following in `CMakeLists.txt`:
```
set(OpenCV_DIR /usr/local/lib)
FIND_PACKAGE(OpenCV REQUIRED)
add_definitions(-DOPENCV)
add_executable(<exeutable_file_name> <./xxx.cpp>)
target_link_libraries(<exeutable_file_name>  ${OpenCV_LIBS})
```
