#include <iostream>

//https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/

//time: O(logb), space: O(1)
int moduloMultiplication(int a, int b, int mod) {
    int res = 0; // Initialize result 

    // Update a if it is more than 
    // or equal to mod 
    a %= mod;

    while (b){ 
        /*
        If b is even then 
        a * b = 2 * a * (b / 2), 
        otherwise 
        a * b = a + a * (b - 1)
        */
        // If b is odd, add 'a' to result 
        if(b & 1){
            res = (res + a) % mod;
        }

        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 

        b >>= 1; // b = b / 2 
    } 

    return res; 
} 
    
int main() {
    // your code goes here
    int a = 1e9, b = 1e9, MOD = 1e9+7;
    int res;
    res = moduloMultiplication(a, b, MOD);
    std::cout << res << std::endl;
    return 0;
}
