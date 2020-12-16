# flann
[flann](https://github.com/mariusmuja/flann) is a library for performing fast approximate nearest neighbor searches in high dimensional spaces.

## Install using apt
```sh
apt-get install -y libflann-dev
```

## Install from source
Ref: [成功在Ubuntu 16.04環境中安裝 PCL 1.8.1 & python-pcl(Python 2.7.12 & Python 3.5.2)](https://medium.com/@ss4365gg/%E6%88%90%E5%8A%9F%E5%9C%A8ubuntu-16-04%E7%92%B0%E5%A2%83%E4%B8%AD%E5%AE%89%E8%A3%9D-pcl-1-8-1-python-pcl-a016b711bc4).

First download `flann.1.9.1.tar.gz`(or other versions) from its [github repo](https://github.com/mariusmuja/flann/tree/1.9.1), and then untar it.

Prerequisite:

[HDF5](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#hdf5), [Googletest](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#gtestgoogletest), [Latex](https://github.com/keineahnung2345/linux-commands/blob/master/Linux%20packages.md#latex)

Build:
```sh
mkdir build && cd build
cmake ..
make
make install
```

### Troubleshooting

In `cmake ..`, there could be an error: 

```
No SOURCES given to target: flann_cpp
# ...
No SOURCES given to target: flann
```

Following [heirecka's solution](https://github.com/mariusmuja/flann/issues/369#issuecomment-378421544), a workaround is to create `empty.cpp` under `src/cpp`,

and then revise `src/cpp/CMakeLists.txt`, change its 

line 32:
```
add_library(flann_cpp SHARED "")
```
and line 86:
```
add_library(flann SHARED "")
```

to:

line 32:
```
add_library(flann_cpp SHARED empty.cpp)
```
and line 86:
```
add_library(flann SHARED empty.cpp)
```

