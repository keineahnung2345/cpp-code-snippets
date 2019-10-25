# base64

The Github repo [ReneNyffenegger/cpp-base64](https://github.com/ReneNyffenegger/cpp-base64) provides Base64 encoding and decoding with c++.

## installation

First clone the repo [ReneNyffenegger/cpp-base64](https://github.com/ReneNyffenegger/cpp-base64) and then run:
```sh
./compile-and-run-test
```

## use it in another project

In CMakeLists.txt:
```
include_directories(<cpp-base64_installation_dir>)

add_executable(<exe_name> ./xxx.cpp <cpp-base64_installation_dir>/base64.cpp)
```
