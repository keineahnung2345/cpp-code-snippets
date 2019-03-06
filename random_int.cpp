#include <iostream>

using namespace std;

int main()
{
    srand(1); //set random seed for reproducible result
    // this will generate numbers from 3 to 3+5=8
    for(int i = 0; i < 10; i++){
        cout << rand()%5+3 << " ";
    }
    return 0;
}
