# Qhull
[Qhull](https://github.com/qhull/qhull) is a library for Convex hull, Delaunay triangulation, Voronoi diagrams, Halfspace intersection.

## Install using apt
```sh
apt-get install libqhull-dev
```

## Install from source

First download [qhull-2019-src-7.3.2.tgz](http://www.qhull.org/download/qhull-2019-src-7.3.2.tgz) from http://www.qhull.org/download/

And then follows http://www.qhull.org/README.txt:

```sh
tar -xzf qhull-2019-src-7.3.2.tgz
cd qhull-2019.1
cd build
#cmake --help  # List build generators
#make -G "<generator>" .. && cmake ..  
cmake ..
make
make install
```
