# cpr
cpr serves as a client.

## installation
1. clone the repo: https://github.com/whoshuu/cpr
2. copy the subdirectory `cpr`(it contains auth.cpp, cookies.cpp, error.cpp, payload.cpp, ssl_options.cpp, CMakeLists.txt,...) into your project's `src` folder

## use it in another project
In CMakeLists.txt:
```
add_subdirectory(./src/cpr)

add_library(<lib_name> SHARED <src_files>)
target_link_libraries(<lib_name> cpr)

add_executable(<exe_name> <src_files>)
target_link_libraries(<exe_name> cpr)
```
