#include <iostream>

using namespace std;

int MOD = 1e9+7;

int fact(int n) { 
    long long res = 1; 
    for (int i = 2; i <= n; i++) 
        res = (res * i) % MOD;
    return res; 
};
    
int main()
{
    cout << fact(5) << endl;

    return 0;
}

//120
