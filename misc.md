## Compile
[Compiling with g++](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/)

### Check g++ default c++ standard version
[Which C++ standard is the default when compiling with g++?](https://stackoverflow.com/questions/44734397/which-c-standard-is-the-default-when-compiling-with-g)
```sh
g++ -dM -E -x c++  /dev/null | grep -F __cplusplus
```
Sample output:
```
#define __cplusplus 199711L
```

### Compile, specify c++ version
[to_string is not a member of std, says g++ (mingw)](https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw)
```sh
g++ xxx.cpp -std=c++11
```

This solves the error:
```
/usr/include/c++/5/bits/c++0x_warning.h:32:2: error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
 #error This file requires compiler and library support \
```

### specify include directory
```sh
g++ xxx.cpp -I /usr/local/include
```

### make
Dry run:

[How do I force make/GCC to show me the commands?](https://stackoverflow.com/questions/5820303/how-do-i-force-make-gcc-to-show-me-the-commands)
```sh
make -n
```

Install dry run:

[What's the opposite of 'make install', i.e. how do you uninstall a library in Linux?](https://stackoverflow.com/questions/1439950/whats-the-opposite-of-make-install-i-e-how-do-you-uninstall-a-library-in-li)
```sh
make -n install
```

make clean:

removes any intermediate or output files from your source / build tree. However, it only affects the source / build tree; it does not touch the rest of the filesystem and so will not remove previously installed software.

```sh
make clean
```

make uninstall:

```sh
make uninstall
```
But it's up to the library's authors to provide this.

### CMakeLists.txt
#### fundamental

```
cmake_minimum_required(VERSION 3.5)
project(name)
# specify the c++ version to use
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC -std=c++11")
# the compiler flags for compiling C sources 
message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
# the compiler flags for compiling C++ sources 
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

find_package(OpenCV REQUIRED)
set(SOURCE_FILES ./src/file1.cpp ./src/file2.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)

# create a executable file
add_executable(<executable_file_name> ./src/main.cpp)
target_link_libraries(<executable_file_name> ${OpenCV_LIBS})

# create a shared object
add_library(<library_name> SHARED ${SOURCE_FILES})
target_link_libraries(<library_name> ${OpenCV_LIBS})
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

Other types of variable: [What's the CMake syntax to set and use variables?](https://stackoverflow.com/questions/31037882/whats-the-cmake-syntax-to-set-and-use-variables)

#### add definition
This equals to add `#define MYVAR` in `.cpp` or `.h` files.
```
add_definitions(-D MYVAR)
```

#### CMAKE_SOURCE_DIR v.s. PROJECT_SOURCE_DIR
[Are CMAKE_SOURCE_DIR and PROJECT_SOURCE_DIR the same in CMake?](https://stackoverflow.com/questions/32028667/are-cmake-source-dir-and-project-source-dir-the-same-in-cmake)

`CMAKE_SOURCE_DIR`: the folder containing the top-level CMakeLists.txt

`PROJECT_SOURCE_DIR`: the inner-most folder containing CMakeLists.txt with `project()` command

#### project structure
[CMake with include and source paths - basic setup](https://stackoverflow.com/questions/8304190/cmake-with-include-and-source-paths-basic-setup)

### make, specify number of jobs as the number of processing units available
```sh
make -j $(nproc)
```

### cmake in debug mode and make in verbose mode
[Using CMake with GNU Make: How can I see the exact commands?](https://stackoverflow.com/questions/2670121/using-cmake-with-gnu-make-how-can-i-see-the-exact-commands)
```sh
cmake -DCMAKE_BUILD_TYPE=DEBUG ..
make VERBOSE=1 2>../log.txt
```

The `2>../log.txt` redirect error message into a log file.

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

## ./a.out: error while loading shared libraries: xxx.so: cannot open shared object file: No such file or directory
[g++ executable cannot find shared library](https://stackoverflow.com/questions/12000990/g-executable-cannot-find-shared-library)
```sh
LD_LIBRARY_PATH=/usr/local/lib ./a.out
```
or
```sh
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```

## stack smashing detected
From [StackOverflow - Stack smashing detected](https://stackoverflow.com/questions/1345670/stack-smashing-detected/50690687), add the following in `CMakeLists` to temporarily get rid of this error:
```
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-stack-protector -std=c++11")
```

## c++: internal compiler error: Killed (program cc1plus)
[make -j 8 g++: internal compiler error: Killed (program cc1plus)](https://stackoverflow.com/questions/30887143/make-j-8-g-internal-compiler-error-killed-program-cc1plus)

That's probably `make -j4` uses to much memory, so it's killed by system, try using `make -j1` instead.

Another method is to tell kswapd0 to only move stuff to SWAP when you are completely out of RAM([kswapd0 is taking a lot of cpu](https://askubuntu.com/questions/259739/kswapd0-is-taking-a-lot-of-cpu/530661)):
```sh
echo vm.swappiness=0 | sudo tee -a /etc/sysctl.conf
```

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

## specify OpenCV path while cmake
```
set(OpenCV_DIR /usr/local/lib/cmake/opencv4) # set to system installation directory
set(OpenCV_DIR ~/installation/opencv-4.1.2/build) # set to opencv build directory
FIND_PACKAGE(OpenCV REQUIRED)
```

Another method: [cmake find_package specify path](https://stackoverflow.com/questions/49816206/cmake-find-package-specify-path)

## ccmake
Its usage: [A ccmake walk-through for the impatients](https://graal.ens-lyon.fr/diet/UsersManualDIET2.4/node22.html).

## Conventions
[Separating class code into a header and cpp file](https://stackoverflow.com/questions/9579930/separating-class-code-into-a-header-and-cpp-file)

## Macros
### #define, #if, #elif, #else, #end
[Preprocessor check if multiple defines are not defined](https://stackoverflow.com/questions/17237545/preprocessor-check-if-multiple-defines-are-not-defined)
```cpp
#define <MACRO_A>

#ifdef <MACRO_A>
#elif defined(<MACRO_B>)
#elif !define(<MACRO_C>) && !define(<MACRO_D>)
#elif !define(<MACRO_E>) || !define(<MACRO_F>)
#else
#end
```

### include guard
Naming convention for include guard: [How to properly name include guards in c++ [closed]](https://stackoverflow.com/questions/49688518/how-to-properly-name-include-guards-in-c)

```
For a file named "baz.h" in a project named "foo", in submodule "bar", I'd name the guard FOO_BAR_BAZ_H.
```

### #pragma once
```cpp
#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__
// ...
#endif
```
can be replaced with:
```cpp
#pragma once
// ...
```

## mimic of python if __name__ == '__main__':

In Python, say we have `foo.py` and `bar.py`, and they both have `if __name__ == '__main__':`(we can think this as `main` function in C++). We can easily `import foo` from `bar.py` or `import bar` from `foo.py` without any problem.

But in C++, if `foo.cpp` and `bar.cpp` both have `main` fucntion, then when they are compiled together(`g++ foo.cpp bar.cpp`), there will be the linker error:

```
multiple definition of `main'
```

Indicating that there are multiple functions named `main` are being linked together. 

So how to only enable one `main` function when compiling multiple `.cpp` files together? 

Following is a workaround:

In `foo.cpp`:

```cpp
#include "foo.h"
#include "bar.h"

int foo(){
    return 0;
}

#ifdef FOO
int main(){
    return 0;
};
#endif
```

And in `bar.cpp`:

```cpp
int bar(){
    return 0;
}

#ifdef BAR
int main(){
    return 0;
};
#endif
```

Wrap their `main` function with the macro `ifdef-endif`, and when compiling them, use:

```sh
g++ -DFOO foo.cpp bar.cpp
```

to only activate `foo.cpp`'s `main` function!
