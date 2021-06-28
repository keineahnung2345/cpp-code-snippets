# g2o

## install dependencies
```sh
sudo apt install cmake -y
sudo apt install libeigen3-dev -y
sudo apt install libsuitesparse-dev -y
sudo apt install qtdeclarative5-dev -y
sudo apt install qt5-qmake -y
sudo apt install libqglviewer-dev-qt5 -y
```

## install from source
```sh
git clone https://github.com/RainerKuemmerle/g2o.git
cd g2o/
mkdir build
cd build
cmake ..
make -j8
sudo make install
```
