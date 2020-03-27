#include <iostream>
#include <chrono>

//https://kheresy.wordpress.com/2014/01/09/c11-condition-variable/

// #define LINUX
#define MODE 1

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
bool gDone;

void func1(){
    std::cout << "[" << this_thread::get_id() << "] Thread started." << std::endl;
    //lock gMutex
    unique_lock<mutex> mLock(gMutex);
    //when we call wait(), gMutex will be automatically unlocked
    gCV.wait( mLock );
    std::cout << "[" << this_thread::get_id() << "] Thread end." << std::endl;
}

void func2(){
    std::cout << "[" << this_thread::get_id() << "] Thread started." << std::endl;
    //lock gMutex
    unique_lock<mutex> mLock(gMutex);
    //when we call wait(), gMutex will be automatically unlocked
    /*
    This is different from func1 in that when it receives notification, 
    it still need to check whether gDone is true,
    if gDone is still false, then it will keep waiting
    */
#if MODE == 1
    // gCV.wait(mLock, []() { return gDone; });
#elif MODE == 2
    while( !gDone )
		gCV.wait( mLock );
#endif
    std::cout << "[" << this_thread::get_id() << "] Thread end." << std::endl;
}

void func3(){
    std::cout << "[" << this_thread::get_id() << "] Thread started." << std::endl;
    unique_lock<mutex> mLock(gMutex);
    /*
    Even if it doesn't been notified, it will stop waiting after 2 seonds.
    */
    gCV.wait_for( mLock, std::chrono::seconds(2) );
    std::cout << "[" << this_thread::get_id() << "] Thread end." << std::endl;
}

void func4(){
    std::cout << "[" << this_thread::get_id() << "] Thread started." << std::endl;
    unique_lock<mutex> mLock(gMutex);
    /*
    If it's not notified, it will wait until now + 2 seconds.
    */
    gCV.wait_until( mLock, std::chrono::system_clock::now() + std::chrono::seconds(2) );
    std::cout << "[" << this_thread::get_id() << "] Thread end." << std::endl;
}
 
int main( int argc, char** argv ){
    std::cout << "[Main] create new thread t1" << std::endl;
    thread t1(func1);
    std::cout << "[Main] wait 1 second" << std::endl;
    this_thread::sleep_for( std::chrono::seconds(1) );
    std::cout << "[Main] send notify" << std::endl;
    gCV.notify_all();
    std::cout << "[Main] wait thread t1 stop" << std::endl;
    t1.join();
    std::cout << std::endl;

    std::cout << "[Main] create new thread t2" << std::endl;
    thread t2(func2);
    std::cout << "[Main] wait 1 second" << std::endl;
    this_thread::sleep_for( std::chrono::seconds(1) );
    std::cout << "[Main] send notify" << std::endl;
    gDone = true;
    gCV.notify_all();
    std::cout << "[Main] wait thread t2 stop" << std::endl;
    t2.join();
    std::cout << std::endl;
    
    std::cout << "[Main] create new thread t3" << std::endl;
    thread t3(func3);
    std::cout << "[Main] wait thread t3 stop" << std::endl;
    t3.join();
    std::cout << std::endl;
    
    std::cout << "[Main] create new thread t4" << std::endl;
    thread t4(func4);
    std::cout << "[Main] wait thread t4 stop" << std::endl;
    t4.join();

    return 0;
}

/*
[Main] create new thread t1
[Main] wait 1 second
[47900612556544] Thread started.
[Main] send notify
[Main] wait thread t1 stop
[47900612556544] Thread end.

[Main] create new thread t2
[Main] wait 1 second
[47900612556544] Thread started.
[47900612556544] Thread end.
[Main] send notify
[Main] wait thread t2 stop

[Main] create new thread t3
[Main] wait thread t3 stop
[47900612556544] Thread started.
[47900612556544] Thread end.

[Main] create new thread t4
[Main] wait thread t4 stop
[47900612556544] Thread started.
[47900612556544] Thread end.
*/
