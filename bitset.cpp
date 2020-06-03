#include <iostream>
#include <bitset>
 
using namespace std;
 
int main() {
	//the index starts from the least significant bit
	//initialize 0th bit as 1
    bitset<5> bs(1);
    cout << "count: " << bs.count() << 
    		", str: " << bs.to_string() << 
    		", long: " << bs.to_ulong() << endl;
 
 
    bs.flip(2);
    cout << "count: " << bs.count() << 
    		", str: " << bs.to_string() << 
    		", long: " << bs.to_ulong() << endl;
 
    bs.flip(4);
    cout << "count: " << bs.count() << 
    		", str: " << bs.to_string() << 
    		", long: " << bs.to_ulong() << endl;
    return 0;
}

/*
count: 1, str: 00001, long: 1
count: 2, str: 00101, long: 5
count: 3, str: 10101, long: 21
*/
