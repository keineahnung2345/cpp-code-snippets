#include <iostream>
  
//https://stackoverflow.com/questions/29388711/c-how-to-get-length-of-bits-of-a-variable
int main() {
    unsigned int bits;
    int ox;
    unsigned int x;
    std::cin >> ox;
    x = ox; //convert to unsigned int
    x = (x < 0)?(-x):x;
    for(bits = 0; x != 0; bits++) x >>= 1;
    std::cout << ox << ", " << bits << std::endl;
    return 0;
}

/*
5, 3
-2, 32
*/
