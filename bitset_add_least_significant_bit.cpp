#include <iostream>
#include <bitset>

using namespace std;

//https://stackoverflow.com/questions/757059/position-of-least-significant-bit-that-is-set

int main() {
    bitset<3> x(6);
    bitset<3> y = bitset<3>(x.to_ulong()-1);
    cout << "x: " << x << ", x-1: " << y << endl;
    cout << "remove " << x << "'s least significant bit: " << (x & y) << endl;
    cout << x << "'s least significant bit: " << (x & ~y) << endl;
    return 0;
}
