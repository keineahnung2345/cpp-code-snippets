#include <iostream> 
using namespace std; 

//https://www.geeksforgeeks.org/find-significant-set-bit-number/

int setBitNumber(int n) 
{
    // Below steps set bits after MSB (including itself)
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n = n + 1;

    return (n >> 1);
} 
  
// Driver code 
int main() 
{
    cout << setBitNumber(273) << endl; //256
    cout << setBitNumber(256) << endl; //256
    return 0; 
}
