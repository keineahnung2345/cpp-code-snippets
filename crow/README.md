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

## use it in another project
Reference to [undefined reference to symbol 'pthread_sigmask@@GLIBC_2.2.5' 解决方法](https://blog.csdn.net/DONGHUIB/article/details/82824011).

In CMakeLists.txt:
```
find_package(Threads)

include_directories(<crow_dir>/amalgamate)
# boost is required by crow
link_directories(<boost_installation_dir>/lib)
link_libraries(boost_system boost_thread)

add_executable(<exe_name> ./xxx.cpp)
target_link_libraries(<exe_name> ${CMAKE_THREAD_LIBS_INIT})
```
