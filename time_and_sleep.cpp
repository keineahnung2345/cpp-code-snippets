#include <iostream>
#include <chrono>
#include <thread>
#include <random>

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
    long start2 = get_time();
    std::cout << "start time: " << start2 << std::endl;
    std::cout << "now sleep for 4605 milliseconds." << std::endl;
    std::chrono::milliseconds timespan2(4605); // or whatever
    std::this_thread::sleep_for(timespan2);
    long end2 = get_time();
    std::cout << "end time: " << end2 << std::endl;
    std::cout << "it takes: " << end2 - start2 << " milliseconds." << std::endl;
    //https://www.epochconverter.com/
    //https://stackoverflow.com/questions/5212018/how-to-make-c-cout-not-use-scientific-notation
    //add std::fixed to not using scientific notation
    //std::cout << "now: " << std::fixed << now << std::endl;
    
    /*
    start time: 1571821790057
    now sleep for 4605 milliseconds.
    end time: 1571821794663
    it takes: 4606 milliseconds.
    */

    //sleep for a random period
    //https://stackoverflow.com/questions/7577452/random-time-delay
    std::mt19937_64 eng{std::random_device{}()};  // or seed however you want
    std::uniform_int_distribution<> dist{10, 100};
    std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});

    // method 3 : clock, not accurate
    //https://www.geeksforgeeks.org/clock-function-in-c-c/
    //https://stackoverflow.com/questions/10455905/why-is-clocks-per-sec-not-the-actual-number-of-clocks-per-second
    clock_t start3 = clock();
    std::cout << "start time: " << start3 << std::endl;
    std::cout << "now sleep for 4605 milliseconds." << std::endl;
    std::chrono::milliseconds timespan3(4605); // or whatever
    std::this_thread::sleep_for(timespan3);
    clock_t end3 = clock();
    std::cout << "end time: " << end3 << std::endl;
    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << "it takes: " << (float)(end3 - start3)*1000/CLOCKS_PER_SEC << " milliseconds." << std::endl;

    /*
    start time: 3160
    now sleep for 4605 milliseconds.
    end time: 3186
    CLOCKS_PER_SEC: 1000000
    it takes: 0.026 milliseconds.
    */
    return 0;
}
