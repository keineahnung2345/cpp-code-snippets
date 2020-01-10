# MySQL connector

## Installation
```sh
sudo apt-get install libmysqlcppconn-dev
```

## Use it in another project
### g++
Adapted from [C++ / mysql Connector - undefined reference to get_driver_instance - already tried the easy stuff](https://stackoverflow.com/questions/15995319/c-mysql-connector-undefined-reference-to-get-driver-instance-already-tri):
```sh
g++ mysql.cpp -I/usr/include/mysql-cppconn-8/jdbc -lmysqlcppconn
```
