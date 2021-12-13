#include <atomic>
#include <iostream>

// https://en.cppreference.com/w/cpp/atomic/atomic/compare_exchange
// https://blog.csdn.net/feikudai8460/article/details/107035480

int main() {
    for(size_t i = 0; i < 2; ++i) {
        std::atomic<int> balance  = 0;
        int              expected = i;
        int              desired  = -1;

        std::cout << "initial value: " << balance.load()
                  << ", expect it to be: " << expected << std::endl;

        if(!balance.compare_exchange_strong(expected, desired)) {
            std::cout << "check failed, expected becomes: " << expected
                      << std::endl;
        }
        else {
            std::cout << "check successed, current value becomes: "
                      << balance.load() << std::endl;
            balance.store(1);
            std::cout << "it's updated to: " << balance.load() << std::endl;
        }
        std::cout << "===========================" << std::endl;
    }

    return 0;
}

/**
initial value: 0, expect it to be: 0
check successed, current value becomes: -1
it's updated to: 1
===========================
initial value: 0, expect it to be: 1
check failed, expected becomes: 0
===========================
**/
