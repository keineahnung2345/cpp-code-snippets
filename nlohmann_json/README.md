# nlohmann/json

## installation
1. clone the repo https://github.com/nlohmann/json
2. run the following:
```sh
mkdir build
cd build
cmake ..
make -j8
sudo make install
```

## cmake
### use nlohmann/json after installing
In CMakeLists.txt:
```
FIND_PACKAGE(nlohmann_json REQUIRED)
add_executable(<exe_name> <src_files>)
target_link_libraries(<exe_name> nlohmann_json::nlohmann_json)
```

### use nlohmann/json without installing
It seems it's hard to create a `.so` file for nlohmann/json, so the workaround is to copy the `builid` folder to your project, and then in CMakeLists.txt:

```
set(nlohmann_json_DIR ${CMAKE_SOURCE_DIR}/<json_build_folder>)
add_executable(<exe_name> <src_files>)
target_link_libraries(<exe_name> nlohmann_json::nlohmann_json)
```
