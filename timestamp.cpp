#include <iostream>
using namespace std;

// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

std::string get_timestamp() {
    time_t now = time(NULL);
    struct tm* ltm = localtime(&now);
    char buffer[80];
 
    strftime(buffer, 80, "%Y-%m-%d-%H-%M-%S", ltm);
 
    return std::string(buffer);
}
 
int main() {
    std::cout << "current timestamp: " << get_timestamp() << std::endl;
    //current timestamp: 2021-08-30-01-53-30
    return 0;
}
