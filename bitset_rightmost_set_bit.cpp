#include <iostream>
#include <bitset>

using namespace std;

//two's complement
//https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html
//rightmost set bit
//https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
//https://www.geeksforgeeks.org/find-significant-set-bit-number/
//https://stackoverflow.com/questions/757059/position-of-least-significant-bit-that-is-set

int main() {
    bitset<3> x(6);
    bitset<3> x_sub_1 = bitset<3>(x.to_ulong()-1);
    bitset<3> x_comp_add_1 = bitset<3>((~x).to_ulong()+1);
    cout << "x: " << x << ", x-1: " << x_sub_1 << endl;
    //two way to get rightmost set bit
    cout << x << "'s rightmost set bit: " << (x & ~x_sub_1) << " = " << x_comp_add_1 << endl;
    cout << "remove " << x << "'s rightmost set bit: " << (x & x_sub_1) << endl;
    return 0;
}
