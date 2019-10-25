cmake_minimum_required(VERSION 3.5)
project(base64)
set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenCV REQUIRED)

include_directories(<cpp-base64_installation_dir>)
add_executable(encode_image encode_image.cpp /<cpp-base64_installation_dir>/base64.cpp)
target_link_libraries(encode_image ${OpenCV_LIBS})
