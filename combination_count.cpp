#include <iostream>

using namespace std;

int MOD = 1e9+7;

int fact(int n) 
{ 
    long long res = 1; 
    for (int i = 2; i <= n; i++) 
        res = (res * i) % MOD;
    return res; 
};

int power(int x, unsigned int y){ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % MOD; 
    p = (p * p) % MOD; 

    return (y%2 == 0)? p : (x * p) % MOD; 
};

// Function to return gcd of a and b 
int gcd(int a, int b){ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
};

// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
int modInverse(int a){ 
    int g = gcd(a, MOD); 
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
        return power(a, MOD-2);
    } 
};

int nCr(int n, int r) 
{ 
    long long fr_inverse = modInverse(fact(r));
    long long fnr_inverse = modInverse(fact(n - r));
    return ((fact(n) * fr_inverse) % MOD * fnr_inverse) % MOD; 
};

    
int main()
{
    cout << nCr(10, 5) << endl; //252
    cout << nCr(70, 30) << endl; //709329438
    
    return 0;
}
