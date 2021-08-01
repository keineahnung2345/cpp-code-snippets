# Cartographer

## install without ROS
Just follow [Cartographer doc](https://google-cartographer.readthedocs.io/en/latest/index.html).

```sh
sudo apt update -y
sudo apt install -y \
    clang \
    cmake \
    g++ \
    git \
    google-mock \
    libboost-all-dev \
    libcairo2-dev \
    libcurl4-openssl-dev \
    libeigen3-dev \
    libgflags-dev \
    libgoogle-glog-dev \
    liblua5.2-dev \
    libsuitesparse-dev \
    lsb-release \
    ninja-build \
    stow
```

```sh
# For ubuntun 20.04
# sudo apt install libceres-dev # I've installed it before
sudo apt install -y python3-sphinx libgmock-dev protobuf-compiler
```

```sh
git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp
# git checkout d902eb869bcfacc1bad14933ed9af4bed006d481
mkdir build
cd build
cmake -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
  -DCMAKE_INSTALL_PREFIX=/usr/local/stow/absl \
  ..
ninja
sudo ninja install
cd /usr/local/stow
sudo stow absl

```

```sh
# VERSION="v3.4.1"

# Build and install proto3.
git clone https://github.com/google/protobuf.git
cd protobuf
# git checkout tags/${VERSION}
mkdir build
cd build
cmake -G Ninja \
  -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
  -DCMAKE_BUILD_TYPE=Release \
  -Dprotobuf_BUILD_TESTS=OFF \
  ../cmake
ninja
sudo ninja install
```

```sh
git clone https://github.com/cartographer-project/cartographer.git
cd cartographer
mkdir build
cd build
cmake .. -G Ninja
ninja
CTEST_OUTPUT_ON_FAILURE=1 ninja test
sudo ninja install

```

## install with ROS

Just follow [Compiling Cartographer ROS](https://google-cartographer-ros.readthedocs.io/en/latest/compilation.html).
