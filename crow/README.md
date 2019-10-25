# crow
Crow is C++ microframework for web, it serves as a web server.

## installation
First clone [ipkn/crow](https://github.com/ipkn/crow) and replace its CMakeLists.txt with CMakeLists.txt from this repo.

Install dependencies:
```sh
sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
```
And then:
```
mkdir build
cd build
cmake ..
make
```
