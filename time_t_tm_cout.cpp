#include <iostream>
#include <iomanip> //setw, setfill

//g++ time_t_tm_cout.cpp -std=c++11

int main(){
    std::time_t timestamp = std::time(nullptr);
    tm* tm_local = std::localtime(&timestamp);
    std::cout << "[";
    std::cout << std::setw(2) << std::setfill('0') << 1 + tm_local->tm_mon << "/";
    std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_mday << "/";
    std::cout << std::setw(4) << std::setfill('0') << 1900 + tm_local->tm_year << "-";
    std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_hour << ":";
    std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_min << ":";
    std::cout << std::setw(2) << std::setfill('0') << tm_local->tm_sec << "] ";
    std::cout << std::endl;
    return 0;
}

/*
[01/22/2020-22:44:46] 
*/
