#include <iostream>

//https://kheresy.wordpress.com/2012/07/06/multi-thread-programming-in-c-thread-p1/

#ifdef LINUX
    #include <thread>
    using namespace std;
#else
    #include "mingw-std-threads/mingw.thread.h"
    using namespace mingw_stdthread;
#endif

class Rectangle{
public:
    int width;
    int height;
    Rectangle() : width(0), height(0){};
    Rectangle(int w, int h) : width(w), height(h){};
    int getArea(){
        return width * height;
    }
};

class MyFunctor{
public:
    int count;

    MyFunctor(){
        count = 0;
    }

    void operator()(){
        count++;
    }
};

void func(){
    long double ans = 0;
    for(int i = 0; i < (1 << 10); i++){
        for(int j = 1; j < (1 << 10); j++){
            ans += (double)i/j;
        }
    }
    std::cout << "func calculates: " << ans << std::endl;
}

void func2(int i){
    std::cout << "func2 receives " << i << std::endl;
}

void func3(){
    thread::id this_id = this_thread::get_id();


    std::cout << "thread " << this_id << " sleeping...\n";

#ifdef LINUX
    std::this_thread::sleep_for(std::chrono::seconds(1));
#else
    this_thread::sleep_for(std::chrono::seconds(1));
#endif
}

int main(){
    thread t1(func);
    /*
    If commented: 
    Error: Must join() or detach() a thread before destroying it.
    3.93261e+006
    terminate called without an active exception
    */
    t1.join();

    //10 is the parameter of func2
    thread t2(func2, 10);
    t2.join();

    MyFunctor fctor;
    //pass by value, fctor.count is still 0
    thread t3(fctor);
    t3.join();
    std::cout << "After t3's execution, count is " << fctor.count << std::endl;

    //pass by reference, fctor.count becomes 1
    thread t4(std::ref(fctor));
    t4.join();
    std::cout << "After t4's execution, count is " << fctor.count << std::endl;

    std::cout << "hardware concurrency: " << thread::hardware_concurrency << std::endl;

    thread t5(func3);
    t5.join();
    return 0;
}

/*
func calculates: 3.93261e+006
func2 receives 10
After t3's execution, count is 0
After t4's execution, count is 1
hardware concurrency: 1
thread 2406656 sleeping...
*/
