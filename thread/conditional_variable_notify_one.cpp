#include <iostream>
#include <vector>
#include <chrono>

//https://kheresy.wordpress.com/2014/01/09/c11-condition-variable/

#define LINUX
#define MODE 3

#ifdef LINUX
    #include <thread>
    #include <mutex>
    #include <condition_variable>
    using namespace std;
#else
    #include "mingw-std-threads/mingw.thread.h"
    #include "mingw-std-threads/mingw.mutex.h"
    #include "mingw-std-threads/mingw.condition_variable.h"
    using namespace mingw_stdthread;
#endif
 
mutex gMutex;
condition_variable gCV;
 
void funcThread( size_t idx ){
    std::cout << "[" << idx << "] Thread started." << std::endl;
    unique_lock<mutex> mLock(gMutex);
#if MODE == 1 || MODE == 2
    gCV.wait_for( mLock, std::chrono::seconds(5) );
    std::cout << "[" << idx << "] Thread end." << std::endl;
#elif MODE  == 3
    gCV.wait(mLock);
    this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "[" << idx << "] Thread end, notify next." << std::endl;
    gCV.notify_one();
#endif
}
 
int main( int argc, char** argv ){
    std::vector<thread> vThreads(3);
 
    std::cout << "[Main] create new thread" << std::endl;
    for( size_t i = 0; i < vThreads.size(); ++ i ){
        //the second argument of thread "i" is the argument to "funcThread"
        vThreads[i] = thread(funcThread, i);
    }
 
    std::cout << "[Main] wait 1 second" << std::endl;
    this_thread::sleep_for( std::chrono::seconds(1) );
 
#if MODE == 1
    std::cout << "[Main] send notify to all" << std::endl;
    gCV.notify_all();
#elif MODE == 2 || MODE == 3
    std::cout << "[Main] send notify to one" << std::endl;
    gCV.notify_one();
#endif
 
    std::cout << "[Main] wait 1 second" << std::endl;
    this_thread::sleep_for( std::chrono::seconds(1) );
 
    std::cout << "[Main] wait thread stop" << std::endl;
    for( size_t i = 0; i < vThreads.size(); ++ i ){
        vThreads[i].join();
    }
}

/*
MODE 1
[Main] create new thread
[Main] wait 1 second
[2] Thread started.
[1] Thread started.
[0] Thread started.
[Main] send notify to all
[Main] wait 1 second
[2] Thread end.
[1] Thread end.
[0] Thread end.
[Main] wait thread stop
*/

/*
MODE 2
[Main] create new thread
[Main] wait 1 second
[2] Thread started.
[1] Thread started.
[0] Thread started.
[Main] send notify to one
[Main] wait 1 second
[2] Thread end.
[Main] wait thread stop
[1] Thread end.
[0] Thread end.
*/

/*
MODE 3
[Main] create new thread
[Main] wait 1 second
[2] Thread started.
[1] Thread started.
[0] Thread started.
[Main] send notify to one
[Main] wait 1 second
[2] Thread end, notify next.
[Main] wait thread stop
[1] Thread end, notify next.
[0] Thread end, notify next.
*/
