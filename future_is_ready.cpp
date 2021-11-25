#include <iostream>
#include <future> // std::async, std::future

// https://stackoverflow.com/questions/10890242/get-the-status-of-a-stdfuture
template <typename R>
bool is_ready(std::future<R> const& f) {
    return f.valid() &&
           (f.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
}

int get_int() {
    int x;
    std::cin >> x;  // sets failbit if invalid
    return x;
}

int main() {
    std::future<int> fut = std::async(get_int);

    std::cout << "Please, enter an integer value: ";

    while(true) {
        if(is_ready(fut)) {
            int x = fut.get();
            std::cout << "You entered: " << x << '\n';
            break;
        }
    }

    return 0;
}

/**
Please, enter an integer value: 4
You entered: 4
*/
