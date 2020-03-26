#include <chrono>
#include <iostream>
#include <string>
#include <random>

//https://kheresy.wordpress.com/2012/08/20/multi-thread-programming-in-c-thread-p3/

#define LINUX
#define MODE 2

#ifdef LINUX
    #include <thread>
    #include <mutex>
    using namespace std;
#else
    #include "mingw-std-threads/mingw.thread.h"
    #include "mingw-std-threads/mingw.mutex.h"
    using namespace mingw_stdthread;
#endif

struct bank_account{
    explicit bank_account(std::string name, int money){
        sName = name;
        iMoney = money;
    }

    std::string sName;
    int iMoney;
    mutex mMutex;
};

void transfer( bank_account &from, bank_account &to, int amount ){
#if MODE == 1
    //this will generate deadlock
    lock_guard<mutex> lock1( from.mMutex );

    //add some random delay, so that we can generate dead lock more easily
    std::mt19937_64 eng{std::random_device{}()};  // or seed however you want
    std::uniform_int_distribution<> dist{10, 100};
    std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});

    lock_guard<mutex> lock2( to.mMutex );
#elif MODE == 2
    //an improvement of MODE 1, lock two mutex together
    //lock the two mutex
    std::lock( from.mMutex, to.mMutex );
    /*
    the "adopt_lock" tells it that the mutex is already locked, 
    so it will not lock the mutex again.
    The fucntion of lock_guard now becomes release the lock at proper time.
    */
    lock_guard<mutex> lock1( from.mMutex, adopt_lock );
    lock_guard<mutex> lock2( to.mMutex, adopt_lock );
#elif MODE == 3
    //not lock the two mutex yet
    unique_lock<mutex> lock1( from.mMutex, defer_lock );
    unique_lock<mutex> lock2( to.mMutex, defer_lock );
    // lock both unique_locks without deadlock
    lock( lock1, lock2 );
#elif MODE == 4
    std::lock( from.mMutex, to.mMutex );
#endif

    from.iMoney -= amount;
    to.iMoney += amount;

    // output log
    std::cout << "Transfer " << amount << " from " 
             << from.sName << " to " << to.sName << std::endl;

#if MODE == 4
    from.mMutex.unlock();
    to.mMutex.unlock();
#endif
}

int main(){
    bank_account Account1( "User1", 100 );
    bank_account Account2( "User2", 50 );
    
    std::cout << Account1.sName << " has " << Account1.iMoney << " dollars." << std::endl;
    std::cout << Account2.sName << " has " << Account2.iMoney << " dollars." << std::endl;

    std::cout << "Transfering..." << std::endl;
    thread t1( [&](){ transfer( Account1, Account2, 10 ); } );
    thread t2( [&](){ transfer( Account2, Account1, 5 ); } );

    t1.join();
    t2.join();

    std::cout << "Now " << Account1.sName << " has " << Account1.iMoney << " dollars." << std::endl;
    std::cout << "Now " << Account2.sName << " has " << Account2.iMoney << " dollars." << std::endl;

}

/*
MODE 1:
User1 has 100 dollars.
User2 has 50 dollars.
Transfering...
*/

/*
MODE 2/3/4:
User1 has 100 dollars.
User2 has 50 dollars.
Transfering...
Transfer 10 from User1 to User2
Transfer 5 from User2 to User1
Now User1 has 95 dollars.
Now User2 has 55 dollars.
*/
