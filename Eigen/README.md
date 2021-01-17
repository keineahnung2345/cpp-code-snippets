# Eigen
[Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html) is a C++ template library for linear algebra.

## install from source
According to [How to install eigen 3.3 in Ubuntu 14.04?](https://askubuntu.com/questions/860207/how-to-install-eigen-3-3-in-ubuntu-14-04), Eigen is a header-only library, so we don't have to "install" it.

First download `eigen-3.3.4.tar.gz`(or other newer versions) from its [gitlab repo](https://gitlab.com/libeigen/eigen/-/tree/3.3.4), and then untar it.

Symlink the Eigen folder into `/usr/local/include`:

```sh
ln -s /xxx/eigen-3.3.4/Eigen /usr/local/include/Eigen
```

Also:

```sh
ln -s /xxx/eigen-3.3.4/unsupported/ /usr/local/include/unsupported
```
otherwise when we `make` `pcl`, it will shows `fatal error: unsupported/Eigen/NonLinearOptimization: No such file or directory`.

Note that the arguments of `ln -s` must be full links, otherwise the target will be invalid.
