#include <iostream>
using namespace std;

int main() {
    int x = 6;
    cout << "remove " << x << "'s least significant bit: " << (x & (x-1)) << endl;
    cout << x << "'s least significant bit: " << (x & (~(x-1))) << endl;
    return 0;
}
