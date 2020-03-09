#include <iostream>
#include <bitset>
#include <cmath>
#define FIX_BIT_LENGTH

//https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting

int main(){
    const int x = 128;
#ifdef FIX_BIT_LENGTH
    const std::size_t bit_length = 8;
#else
    const std::size_t bit_length = sizeof(x) * 8;
#endif
    std::cout << "bit_length: " << bit_length << std::endl;
    std::string binary = std::bitset<bit_length>(x).to_string(); //to binary
    std::cout << "binary: " << binary << std::endl;

    unsigned long decimal = std::bitset<bit_length>(binary).to_ulong();
    std::cout << "decimal: " << decimal << std::endl;
    return 0;
}
