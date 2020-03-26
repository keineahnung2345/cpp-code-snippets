#include <iostream>

//https://kheresy.wordpress.com/2012/07/11/multi-thread-programming-in-c-thread-p2/

#define LINUX
//MODE 1: no lock, MODE 2 and 3 : two different way of using lock
#define MODE 1

#ifdef LINUX
    #include <thread>
    #include <mutex>
    using namespace std;
#else
    #include "mingw-std-threads/mingw.thread.h"
    #include "mingw-std-threads/mingw.mutex.h"
    using namespace mingw_stdthread;
#endif

#if MODE == 2 || MODE == 3
std::mutex gMutex;
#endif

void OutputValue(int n) {
#if MODE == 1
#elif MODE == 2
    gMutex.lock();
#elif MODE == 3
    std::unique_lock<std::mutex> mLock(gMutex);
#endif

    std::cout << "Number:";
    for (int i = 0; i < n; ++i)
    {
        this_thread::sleep_for(std::chrono::duration<int, std::milli>(5));
        std::cout << " " << i;
    }
    std::cout << std::endl;

#if MODE == 1
#elif MODE == 2
    gMutex.unlock();
#elif MODE == 3
#endif
}

int main( int argc, char** argv ){
    std::cout << "Normal function call" << std::endl;
    OutputValue( 3 );
    OutputValue( 4 );

    std::cout << "\nCall function with thread" << std::endl;
    thread mThread1( OutputValue, 3 );
    thread mThread2( OutputValue, 4 );
    mThread1.join();
    mThread2.join();
    std::cout << std::endl;

    return 0;
}

/*
MODE 1:
Normal function call
Number: 0 1 2
Number: 0 1 2 3

Call function with thread
Number:Number: 0 0 1 1  22
 3
*/

/*
MODE 2 and 3:
Normal function call
Number: 0 1 2
Number: 0 1 2 3

Call function with thread
Number: 0 1 2
Number: 0 1 2 3
*/
