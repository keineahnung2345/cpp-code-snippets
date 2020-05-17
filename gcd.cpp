#include <iostream>
#include <algorithm> //__gcd

using namespace std;

// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 

int main() {
    cout << gcd(30, 50) << endl; //10
	
    //https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
    cout << __gcd(15, 10) << endl; //5
    return 0;
}
