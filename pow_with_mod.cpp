#include <iostream>
#include <math.h>

using namespace std;

//https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
long long int power(long long int x, long long int y, long long int p){
    long long int res = 1;

    // Update x if it is more than or equal to p
    x = x % p;

    while(y > 0){
        // If y is odd, multiply x with result
        if(y & 1){
            res = (res*x) % p;
        }

        // y must be even now
        y >>= 1;
        x = (x*x) % p;
    }

    return res;
};

int main() {
    int MOD = pow(10, 9) + 7;

    cout << MOD << endl;

	cout << (int)pow(10, 9) % MOD << endl; //correct
	cout << power(10, 9, MOD) << endl; //correct

	cout << (int)pow(10, 10) % MOD << endl; //wrong
	cout << power(10, 10, MOD) << endl; //correct

	//1000000007*9+999999937 = 10000000000
	return 0;
}

/*
1000000007
1000000000
1000000000
147483633
999999937
*/
