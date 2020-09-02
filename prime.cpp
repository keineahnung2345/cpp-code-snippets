#include <iostream>
#include <set>
#include <vector>

using namespace std;

//https://www.geeksforgeeks.org/sieve-of-eratosthenes/

vector<bool> isprime;

void SieveOfEratosthenes(int n){
    for(int p=2; p*p<=n; p++){ 
        if(isprime[p]){
            for(int i=p*p; i<=n; i += p)
                isprime[i] = false;
        }
    }
};

int main()
{
    int max_ele = 100;
    isprime = vector<bool>(max_ele+1, true);
    SieveOfEratosthenes(max_ele);
    
    set<int> primes;
    for(int p = 2; p <= max_ele; ++p){
        if(isprime[p]){
            primes.insert(p);
        }
    }
    
    for(const int& prime : primes){
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
