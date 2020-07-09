# libconfig
[libconfig](https://hyperrealm.github.io/libconfig/) is a C/C++ library for processing configuration files.

## installation
```sh
apt-get install libconfig++-dev
```

## use it in another project

To run the example program, first get `example.cfg` and `example1.cpp` from https://github.com/hyperrealm/libconfig/tree/master/examples/c%2B%2B.

### g++
```sh
g++ `pkg-config --cflags libconfig++` example1.cpp -o example1 `pkg-config --libs libconfig++`
```

or according to [Creating a simple configuration file and parser in C++](https://stackoverflow.com/a/21651886/10651567):

```
g++ example1.cpp -o example1 -lconfig++
```
