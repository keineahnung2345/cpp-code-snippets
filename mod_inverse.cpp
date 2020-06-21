#include <iostream>
using namespace std;

//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
//this works for modInverse(a, m) only when m is prime!

// To compute x^y under modulo m 
int power(int x, unsigned int y, unsigned int m){ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
};

// Function to return gcd of a and b 
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
};

// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
int modInverse(int a, int m){ 
    int g = gcd(a, m); 
    if (g != 1){
        //Fermat's little theorem only works only when m is prime!
        return -1;
    }else{ 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mod m 
        /*
        From Fermat's little theorem,
        when a is not divisible by p,
        a^(p-1) mod m = 1
        here we choose p as m,
        so a^(m-1) mod m = 1
        this is equal to saying that
        a * a^(m-2) mod m = 1
        so we can say that a^(m-2) mod m is the inverse of a
        */
        return power(a, m-2, m);
    } 
};

int main() {
    int a = 3, m = 11; 
    int inv = modInverse(a, m);
    if(inv < 0) cout << "Inverse doesn't exist";
    else cout << "Modular multiplicative inverse is "
        << modInverse(a, m) << endl;
    //Modular multiplicative inverse is 4
    return 0;
}
