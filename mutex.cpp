#include <iostream>
#include <thread>
#include <mutex>
#define CORRECT

int cur = 1;
int n = 15;
std::mutex mtx;

//from leetcode: https://leetcode.com/problems/fizz-buzz-multithreaded/
//ref: http://www.cplusplus.com/reference/mutex/mutex/lock/
//g++ mutex.cpp -std=c++11 -lpthread

void fizz(){
#ifndef CORRECT
    //this will give wrong, unpredictable result
    while(cur <= n){
        if(cur % 3 == 0 && cur % 15 != 0){
            mtx.lock();
            std::cout << " fizz";
            cur++;
            mtx.unlock();
        }
    }
#else
    //this will always gives correct result
    while(true){
        mtx.lock();
        if(cur <= n && cur % 3 == 0 && cur % 15 != 0){
            std::cout << " fizz";
            cur++;
        }
        mtx.unlock();
        if(cur > n) break;
    }
#endif
}

void buzz(){
#ifndef CORRECT
    while(cur <= n){
        if(cur % 5 == 0 && cur % 15 != 0){
            mtx.lock();
            std::cout << " buzz";
            cur++;
            mtx.unlock();
        }
    }
#else
    while(true){
        mtx.lock();
        if(cur <= n && cur % 5 == 0 && cur % 15 != 0){
            std::cout << " buzz";
            cur++;
        }
        mtx.unlock();
        if(cur > n) break;
    }
#endif
}

void fizzbuzz(){
#ifndef CORRECT
    while(cur <= n){
        if(cur % 15 == 0){
            mtx.lock();
            std::cout << " fizzbuzz";
            cur++;
            mtx.unlock();
        }
    }
#else
    while(true){
        mtx.lock();
        if(cur <= n && cur % 15 == 0){
            std::cout << " fizzbuzz";
            cur++;
        }
        mtx.unlock();
        if(cur > n) break;
    }
#endif
}

void num(){
#ifndef CORRECT
    while(cur <= n){
        if(cur % 3 != 0 && cur % 5 != 0){
            mtx.lock();
            std::cout << " " << cur;
            cur++;
            mtx.unlock();
        }
    }
#else
    while(true){
        mtx.lock();
        if(cur <= n && cur % 3 != 0 && cur % 5 != 0){
            std::cout << " " << cur;
            cur++;
        }
        mtx.unlock();
        if(cur > n) break;
    }
#endif
}

int main(){
    std::thread threads[4];
    threads[0] = std::thread(fizz);
    threads[1] = std::thread(buzz);
    threads[2] = std::thread(fizzbuzz);
    threads[3] = std::thread(num);

    for (auto& th : threads) th.join();
    std::cout << std::endl;
    return 0;
}
