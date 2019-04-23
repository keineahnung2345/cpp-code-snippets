#include <iostream>
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
	return 0;
}
