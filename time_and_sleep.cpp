#include <iostream>
#include <chrono>
#include <thread>

// method 2 : chrono
long get_time(){
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    return ms.count();
}

int main(){
    // method 1 : time, it's unit is second
    //https://www.runoob.com/cplusplus/cpp-date-time.html
    time_t start = time(0);
    std::cout << "start time: " << start << std::endl;
    std::cout << "now sleep for 4605 milliseconds." << std::endl;
    std::chrono::milliseconds timespan(4605); // or whatever    
    std::this_thread::sleep_for(timespan);
    time_t end = time(0);
    std::cout << "end time: " << end << std::endl;
    std::cout << "it takes: " << end - start << " seconds." << std::endl;
    /*
    start time: 1571821821
    now sleep for 4605 milliseconds.
    end time: 1571821825
    it takes: 4 seconds.
    */
    
    // method 2 : chrono, it's unit is millisecond
    // https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
    long start = get_time();
    std::cout << "start time: " << start << std::endl;
    std::cout << "now sleep for 4605 milliseconds." << std::endl;
    std::chrono::milliseconds timespan(4605); // or whatever
    std::this_thread::sleep_for(timespan);
    long end = get_time();
    std::cout << "end time: " << end << std::endl;
    std::cout << "it takes: " << end - start << " milliseconds." << std::endl;
    /*
    start time: 1571821790057
    now sleep for 4605 milliseconds.
    end time: 1571821794663
    it takes: 4606 milliseconds.
    */

    // method 3 : clock, not accurate
    //https://www.geeksforgeeks.org/clock-function-in-c-c/
    //https://stackoverflow.com/questions/10455905/why-is-clocks-per-sec-not-the-actual-number-of-clocks-per-second
    clock_t start = clock();
    std::cout << "start time: " << start << std::endl;
    std::cout << "now sleep for 4605 milliseconds." << std::endl;
    std::chrono::milliseconds timespan(4605); // or whatever
    std::this_thread::sleep_for(timespan);
    clock_t end = clock();
    std::cout << "end time: " << end << std::endl;
    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << "it takes: " << (float)(end - start)/CLOCKS_PER_SEC << " milliseconds." << std::endl;
    
    /*
    start time: 763
    now sleep for 4605 milliseconds.
    end time: 802
    CLOCKS_PER_SEC: 1000000
    it takes: 3.9e-05 milliseconds.
    */
    return 0;
}
