# cpp-code-snippets
Some useful C++ code snippets

## Compile
[Compiling with g++](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/)

### Compile, specify c++ version
[to_string is not a member of std, says g++ (mingw)](https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw)
```sh
g++ xxx.cpp -std=c++11
```

### CMakeLists.txt
#### fundamental

```
cmake_minimum_required(VERSION 3.5)
project(name)
set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
set(SOURCE_FILES ./src/file1.cpp ./src/file2.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)
add_executable(<executable_file_name> ./src/main.cpp)
target_link_libraries(<executable_file_name> ${OpenCV_LIBS})
```

Ref: [Configuring an c++ OpenCV project with Cmake](https://stackoverflow.com/questions/13970377/configuring-an-c-opencv-project-with-cmake)

#### set variable and print
[CMake: Output a list with delimiters](https://stackoverflow.com/questions/17666003/cmake-output-a-list-with-delimiters)
```
set(VAR1 hello)
set(LIST1 a b c d)
message("the variable VAR1 is " ${VAR1})
message("the list LIST1 is " "${LIST1}")
```

### make in verbose mode
[Using CMake with GNU Make: How can I see the exact commands?](https://stackoverflow.com/questions/2670121/using-cmake-with-gnu-make-how-can-i-see-the-exact-commands)
```sh
make VERBOSE=1
```

## list the .so dependencies of a executable file
```sh
ldd <executable>
```
Sample output:
```
	libudev.so.1 => /lib/x86_64-linux-gnu/libudev.so.1 (0x00007fc3364fd000)
	libsoxr.so.0 => /usr/lib/x86_64-linux-gnu/libsoxr.so.0 (0x00007fc336297000)
	libnuma.so.1 => /usr/lib/x86_64-linux-gnu/libnuma.so.1 (0x00007fc33608c000)
```

## list symbols from xxx.so
```sh
nm -D <xxx.so> # -D will list dynamic symbols
```
Sample output:
```
0000000000092030 T YoloPluginCtxInit
                 U rename
0000000000104d8f V _ZTS4Yolo
000000000007c425 W _ZSt10_ConstructI7DsImageIEEvPT_DpOT0_
```
`T` for symbol defined in code section, `U` for undefined, `V` and `W` for weak object.

This is helpful for solving the following error:
```
/home/ubuntu/catkin_ws/devel/lib/ros_trans/OpenTrans: symbol lookup error: /home/ubuntu/catkin_ws/devel/lib/libproduct.so: undefined symbol: YoloPluginGetVersion
```

## show the unmangled name of a symbol
```sh
c++filt <symbol(mangled name)>
```

## /usr/bin/ld: cannot find -l\<xxx>
Error message while linking:
```
/usr/bin/ld: cannot find -lcudnn
collect2: error: ld returned 1 exit status
```
Solution:
[https://stackoverflow.com/questions/51451746/cmake-command-line-ld-library-path-and-c-include-dirs](https://stackoverflow.com/questions/51451746/cmake-command-line-ld-library-path-and-c-include-dirs)

First set `LD_LIBRARY_PATH` to the path of that `.so` file, and then add:
```
link_directories( $ENV{LD_LIBRARY_PATH} )
```
into `CMakeLists.txt`.

## specify CUDA path while cmake
[How to let cmake find CUDA](https://stackoverflow.com/questions/19980412/how-to-let-cmake-find-cuda)

Method 1, use `-D` flag while `cmake`:
```sh
cmake -D CUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda ..
```

Method 2, revise `CMakeLists.txt`, before `FIND_PACKAGE(CUDA)`, add one line, this becomes:
```
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda)
FIND_PACKAGE(CUDA)
```
