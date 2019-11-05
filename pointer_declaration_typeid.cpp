#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int *i1, *i2; //put one * per pointer
    int* i3, i4;

    cout << typeid(i1).name() << endl; #Pi
    cout << typeid(i2).name() << endl; #Pi
    cout << typeid(i3).name() << endl; #Pi
    cout << typeid(i4).name() << endl; #i
    
    return 0;
}
