# cpp-code-snippets
Some useful C++ code snippets

## Compile
[Compiling with g++](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/)

## list symbols from xxx.so
```sh
nm -D <xxx.so> # -D will list dynamic symbols
```
Sample output:
```
0000000000092030 T YoloPluginCtxInit
                 U rename
0000000000104d8f V _ZTS4Yolo
000000000007c425 W _ZSt10_ConstructI7DsImageIEEvPT_DpOT0_
```
`T` for symbol defined in code section, `U` for undefined, `V` and `W` for weak object.

This is helpful for solving the following error:
```
/home/ubuntu/catkin_ws/devel/lib/ros_trans/OpenTrans: symbol lookup error: /home/ubuntu/catkin_ws/devel/lib/libproduct.so: undefined symbol: YoloPluginGetVersion
```

## show the unmangled name of a symbol
```sh
c++filt <symbol(mangled name)>
```
