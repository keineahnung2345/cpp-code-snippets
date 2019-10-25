# dlib
dlib is a machine learning library written in C++, it provides C++ and Python API.

It contains the functions of face recognition and facial landmark detection.

Useful links:
[Using dlib from C++](http://dlib.net/compile.html)
[Github - davisking/dlib](https://github.com/davisking/dlib)

## installation
### static library
This generates the static library: `libdlib.a`. 

From the [official instruction](http://dlib.net/compile.html):
```sh
cd examples
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### dynamic library
This generates the dynamic library: `libdlib.so.19.18.0`, also a `libdlib.so` soft-linked to `libdlib.so.19.18.0`.

From [Create a shared library for dlib](https://stackoverflow.com/questions/33996361/create-a-shared-library-for-dlib):
```sh
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=1 ..
make
sudo make install
```

## use it in another project
### g++
```sh
g++ xxx.cpp -L /usr/local/lib -ldlib -lcblas -llapack -std=c++11
```
`/usr/lib/libcblas.so` and `/usr/lib/liblapack.so` are required by dlib.

### cmake
Reference to [Build Dlib on Windows](https://medium.com/beesightsoft/build-dlib-on-windows-534209e8340a).

In CMakeLists.txt:
```
FIND_PACKAGE(dlib REQUIRED)
# if it fails, use:
#set(dlib_DIR /usr/local/lib)
#FIND_PACKAGE(dlib REQUIRED ${dlib_DIR})

add_executable(<exe_name> <src_files>)
target_link_libraries(<exe_name> dlib::dlib)
```
