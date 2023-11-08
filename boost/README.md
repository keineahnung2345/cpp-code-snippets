# boost
boost contains sorts of functions, including uuid.

## installation

### Linux
Prerequisite: `python3-dev`:
```sh
apt-get install -y python3-dev
```
If there is no `python3-dev` installed, it will show the following error in one of the following steps:
```
fatal error: pyconfig.h: No such file or directory
```
After the installation, we can check if `pyconfig.h` exists or not by:
```sh
find /usr -name pyconfig.h
```

First download `boost_1_xx_0.tar.gz` from https://www.boost.org/users/history/, and unzip it.

Check what libraries boost contains. Or go to [boost libraries](https://www.boost.org/doc/libs/1_81_0/libs/libraries.htm).
```sh
./bootstrap.sh --show-libraries
```
Bootstrap, specify the libraries you want to install:
```
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=system
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=thread
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=chrono
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=date_time
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=filesystem
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=iostreams
# https://stackoverflow.com/questions/5539557/boost-and-python-3-x
# without the "--with-python-version" flag, it could find python2 rather than python3
# recommended installing with python3
./bootstrap.sh --prefix=<boost_installation_dir> --with-libraries=python --with-python-version=3.5
```
Note that `system`, `filesystem`, `thread`, `date_time`, `iostreams` are required by `pcl`(they can be concanated with `,` in the above command).

Finally install:
```sh
./b2 install
```

### Windows

Download `boost_1_xx_0.zip` and unzip it to `C:\Program Files\Boost\boost_1_xx_0` or `C:\Program Files (x86)\Boost\boost_1_xx_0` and then in that directory, open `Developer Command Prompt for VS 2019`, run it as Administrator:

```bat
bootstrap.bat
.\b2
```

Then in `C:\Program Files\Boost\boost_1_xx_0\stage\lib` or `C:\Program Files (x86)\Boost\boost_1_xx_0\stage\lib` there will be libraries looking like `libboost_xxx-x64-1_xx.lib` or `libboost_xxx-x32-1_xx.lib`.

## use it in another project
In CMakeLists.txt(adopted from https://github.com/ipkn/crow/blob/master/CMakeLists.txt):
```
# <boost_installation_dir> is the argument passed to prefix when using bootstrap.sh
#set(Boost_INCLUDE_DIR <boost_installation_dir>/include) #this is useless

link_directories(<boost_installation_dir>/lib)
link_libraries(boost_system boost_thread) # to replace find_package( Boost 1.52 COMPONENTS system thread REQUIRED ) 

if (MSVC)
        set(Boost_USE_STATIC_LIBS "On")
        find_package( Boost 1.52 COMPONENTS system thread regex REQUIRED )
else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -pedantic -Wextra")
        #find_package( Boost 1.52 COMPONENTS system thread REQUIRED ) # this fails, so use the following line and also link_libraries(boost_system boost_thread)
        find_package( Boost 1.52 COMPONENTS REQUIRED )
endif()

message("Boost_INCLUDE_DIR ${Boost_INCLUDE_DIR}")
include_directories( ${Boost_INCLUDE_DIR} )
```

or 

```
#https://stackoverflow.com/questions/3016448/how-can-i-get-cmake-to-find-my-alternative-boost-installation
#these could be helpful when boost isn't installed in the default location
#set(BOOST_ROOT <boost_installation_dir>)
#set(BOOST_LIBRARYDIR <boost_installation_dir>/lib)

find_package(Boost REQUIRED log COMPONENTS system thread)
message(STATUS "Boost library status:")
message(STATUS "    version: ${Boost_VERSION}")
message(STATUS "    libraries: ${Boost_LIBRARIES}")
message(STATUS "    include path: ${Boost_INCLUDE_DIRS}")

add_definitions(-DBOOST_LOG_DYN_LINK)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(<exe_name> ${Boost_LIBRARIES})
```

From [How can I get CMake to find my alternative Boost installation?](https://stackoverflow.com/questions/3016448/how-can-i-get-cmake-to-find-my-alternative-boost-installation), we can set `BOOST_ROOT` so that cmake can find boost from custom installation directory.

### Warning: Imported targets not available for Boost version 107100
When coming to:
```
FIND_PACKAGE(Boost xxx)
```
If there is following warning:
```
CMake Warning at /usr/share/cmake-3.5/Modules/FindBoost.cmake:725 (message):
  Imported targets not available for Boost version 107100
Call Stack (most recent call first):
  /usr/share/cmake-3.5/Modules/FindBoost.cmake:763 (_Boost_COMPONENT_DEPENDENCIES)
  /usr/share/cmake-3.5/Modules/FindBoost.cmake:1332 (_Boost_MISSING_DEPENDENCIES)
  CMakeLists.txt:54 (FIND_PACKAGE)
```
It means the `cmake` used to build the project is too old, one needs to update cmake version according to [CMake finds Boost but the imported targets not available for Boost version](https://stackoverflow.com/questions/42123509/cmake-finds-boost-but-the-imported-targets-not-available-for-boost-version).

### Could not find the following Boost libraries: boost_python
When coming to:
```
FIND_PACKAGE(Boost REQUIRED python)
```
If there is following error:
```
CMake Error at /usr/share/cmake-3.5/Modules/FindBoost.cmake:1677 (message):
  Unable to find the requested Boost libraries.

  Boost version: 1.71.0

  Boost include path: /workspace/data/installation/boost_1_71_0/include

  Could not find the following Boost libraries:

          boost_python

  No Boost libraries were found.  You may need to set BOOST_LIBRARYDIR to the
  directory containing Boost libraries or BOOST_ROOT to the location of
  Boost.
Call Stack (most recent call first):
  CMakeLists.txt:53 (FIND_PACKAGE)
```
or:
```
CMake Error at /usr/local/share/cmake-3.16/Modules/FindPackageHandleStandardArgs.cmake:146 (message):
  Could NOT find Boost (missing: python) (found version "1.71.0")
Call Stack (most recent call first):
  /usr/local/share/cmake-3.16/Modules/FindPackageHandleStandardArgs.cmake:393 (_FPHSA_FAILURE_MESSAGE)
  /usr/local/share/cmake-3.16/Modules/FindBoost.cmake:2179 (find_package_handle_standard_args)
  CMakeLists.txt:55 (find_package)

```
One needs to specify python version by changing `FIND_PACKAGE(Boost REQUIRED python)` to `FIND_PACKAGE(Boost REQUIRED python35)` according to [Cmake could not find boost_python](https://stackoverflow.com/questions/56067518/cmake-could-not-find-boost-python).
