# cpr
cpr serves as a client.

## use it in another project
Assuming your project contains the 2 directories: `src` and `include`.

1. clone the repo: https://github.com/whoshuu/cpr
2. copy the subdirectory `cpr`(it contains auth.cpp, cookies.cpp, error.cpp, payload.cpp, ssl_options.cpp, CMakeLists.txt,...) into your project's `src` folder
3. replace the `CMakeLists.txt` under `src/cpr` with the one in this repo
4. copy the subdirectory `include/cpr` into your project's `include` folder

In CMakeLists.txt:
```
include_directories(./include) #contains the folder cpr

add_subdirectory(./src/cpr)

add_library(<lib_name> SHARED <src_files>)
target_link_libraries(<lib_name> cpr)

add_executable(<exe_name> <src_files>)
target_link_libraries(<exe_name> cpr)
```
