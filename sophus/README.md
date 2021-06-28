# sophus
[strasdat/Sophus](https://github.com/strasdat/Sophus)

## install dependency

Install `fmt`：

```sh
sudo apt install libfmt-dev
```

## install from source

[ubuntu18.04下的sophus安装](https://blog.csdn.net/qq_41647175/article/details/103093074)

```sh
git clone https://github.com/strasdat/Sophus.git
mkdir build
cd build/
cmake ..
make -j8
sudo make install
```

## use it in another project
```cmake
cmake_minimum_required(VERSION 3.0)
project(MY_GRAND_PROJECT)

find_package(Sophus REQUIRED)
#find_package(fmt REQUIRED)
find_package(Pangolin REQUIRED)

add_executable(<NAME> <NAME>.cpp)
target_link_libraries(<NAME> Sophus::Sophus ${Pangolin_LIBRARIES} fmt::fmt)
# when used with pangolin: pangolin should be linked before fmt::fmt
# target_link_libraries(<NAME> Sophus::Sophus ${Pangolin_LIBRARIES} fmt::fmt) 
```

```cpp
#include <pangolin/pangolin.h>

// sophus needs fmt, and there are variables named fmt in pangolin, 
// so sophus should be included after pangolin
#include <sophus/se3.hpp>
```
