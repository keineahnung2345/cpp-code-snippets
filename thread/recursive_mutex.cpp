#include <iostream>

//https://kheresy.wordpress.com/2012/08/20/multi-thread-programming-in-c-thread-p3/

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

class ClassA{
public:
    void func1(){
#if MODE == 1
        lock_guard<mutex> lock(mMutex);
#elif MODE == 2
        lock_guard<recursive_mutex> lock(mMutex);
#endif
        std::cout << "Here is func1" << std::endl;
    }

    void func2(){
#if MODE == 1
        lock_guard<mutex> lock(mMutex);
#elif MODE == 2
        lock_guard<recursive_mutex> lock(mMutex);
#endif
        std::cout << "Here is func2" << std::endl;
        std::cout << "func2 is calling func1" << std::endl;
        func1();
        std::cout << "In func2, return from func1" << std::endl;
    }
private:
#if MODE == 1
    mutex mMutex;
#elif MODE == 2
    recursive_mutex mMutex;
#endif
};

int main(){
    ClassA obj;

    obj.func2();

    return 0;
}

/*
MODE 1:
Here is func2
func2 is calling func1
FATAL: Recursive locking of non-recursive mutex detected. Throwing system exception
terminate called after throwing an instance of 'std::system_error'
  what():  Resource deadlock avoided
*/

/*
MODE 2:
Here is func2
func2 is calling func1
Here is func1
In func2, return from func1
*/
