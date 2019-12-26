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
#this could be helpful when boost isn't installed in the default location
#set(BOOST_ROOT <boost_installation_dir>)
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
