#include <iostream>
#include <bitset>

int count_set_bit(int x){
    int bits = 0;
    while(x != 0){
        bits += x&1;
        x >>= 1;
    }
    return bits;
}

int main(){
    int x = 20;

    //Method 1
    std::bitset<5> b(x);
    std::cout << "bitset object: " << b << std::endl; //10010
    std::cout << "its set bit count: " << b.count() << std::endl; //2
    std::cout << "output in index order: ";
    for(int i = 0; i < 5; i++){
        std::cout << b[i]; //0, index start from behind
    }
    std::cout << std::endl;

    //Method 2
    x = 20;
    int bits = count_set_bit(x);
    std::cout << "its set bit count: " << bits << std::endl;
    
    //Method 3;
    x = 20;
    bits = __builtin_popcount(x);
    std::cout << "its set bit count: " << bits << std::endl;
    return 0;
}

/*
bitset object: 10100
its set bit count: 2
output in index order: 00101
its set bit count: 2
its set bit count: 2
*/
