#include <iostream>

using namespace std;

// https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range

int main()
{
    srand(1); //set random seed for reproducible result
    // this will generate numbers from 3(min) to 8(max)
    int min = 3, max = 8;
    for(int i = 0; i < 10; i++){
        cout << min + (rand() % static_cast<int>(max - min + 1)) << " ";
    }
    return 0;
}
