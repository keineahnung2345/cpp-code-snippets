# boost
boost contains sorts of functions, including uuid.

## installation
First download `boost_1_xx_0.tar.gz` from https://www.boost.org/users/history/, and unzip it.

Check what libraries boost contains:
```sh
./bootstrap.sh --show-libraries
```
Bootstrap, specify the libraries you want to install:
```
./bootstrap.sh --prefix=/xxx/boost_1_xx_0/installation --with-libraries=system
./bootstrap.sh --prefix=/xxx/boost_1_xx_0/installation --with-libraries=thread
./bootstrap.sh --prefix=/xxx/boost_1_xx_0/installation --with-libraries=chrono
./bootstrap.sh --prefix=/xxx/boost_1_xx_0/installation --with-libraries=date_time
```
Finally install:
```sh
./b2 install
```
