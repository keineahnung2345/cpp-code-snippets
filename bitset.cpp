#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<5> bs;
    //the index starts from the least significant bit
    bs.flip(2);
    bs.flip(4);
    cout << bs.count() << endl;
    cout << bs.to_string() << endl;
    cout << bs.to_ulong() << endl;
    return 0;
}

/*
2
10100
20
*/
