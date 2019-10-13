# OpenCV
## cmake
To use OpenCV, add the following in `CMakeLists.txt`:
```
set(OpenCV_DIR /usr/local/lib)
FIND_PACKAGE(OpenCV REQUIRED)
add_definitions(-DOPENCV)
add_executable(<exeutable_file_name> <./xxx.cpp>)
target_link_libraries(<exeutable_file_name>  ${OpenCV_LIBS})
```
