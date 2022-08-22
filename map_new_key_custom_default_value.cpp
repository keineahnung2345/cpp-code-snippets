#include <iostream>
#include <map>

using namespace std;

// https://stackoverflow.com/questions/2333728/stdmap-default-value

struct IntDefaultedToMinusOne {
    int t = -1;
    operator int() const { return t; }
};

int main() {
    std::map<std::string, IntDefaultedToMinusOne> mymap;
    cout << mymap["hello"] << endl; // -1
    return 0;
}
