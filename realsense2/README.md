# realsense2

[IntelRealSense/librealsense](https://github.com/IntelRealSense/librealsense)

## install from source

Prerequisite:

```sh
sudo apt install curl zip unzip tar
sudo apt install libudev-dev autoconf
```

Compile and install:
```sh
git clone https://github.com/microsoft/vcpkg
cd vcpkg/
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install realsense2
```
