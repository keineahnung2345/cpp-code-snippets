# pangolin
[stevenlovegrove/Pangolin](https://github.com/stevenlovegrove/Pangolin)

## install dependencies
### OpenGL

```sh
sudo apt install libgl1-mesa-dev
```

### Glew

```sh
sudo apt install libglew-dev
```

### Python3, for drop-down interactive console

```sh
git submodule init && git submodule update
sudo python -m pip install numpy pyopengl Pillow pybind11
sudo apt install pkg-config
```

### Wayland

```sh
sudo apt install libegl1-mesa-dev libwayland-dev libxkbcommon-dev wayland-protocols
```

## install from source

```sh
git clone https://github.com/stevenlovegrove/Pangolin.git
cd Pangolin
mkdir build
cd build
cmake ..
cmake --build .
```
