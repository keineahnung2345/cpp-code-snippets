# tinyxml2
tinyxml2 is a c++ xml parser, its webpage: https://github.com/leethomason/tinyxml2.

More xml parser in c++: [What XML parser should I use in C++? [closed]](https://stackoverflow.com/questions/9387610/what-xml-parser-should-i-use-in-c).

## installation
First clone it from github, and then:
```sh
mkdir build && cd build
cmake ..
make -j8
sudo make install
```

## use it in another project

First set `LD_LIBRARY_PATH`:
```sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

In `xxx.cpp`:
```cpp
#include <tinyxml2.h>
//include other headers...

using namespace tinyxml2;

//main program here...
```

Compile and run it with:
```sh
g++ xxx.cpp -ltinyxml2
./a.out
```
