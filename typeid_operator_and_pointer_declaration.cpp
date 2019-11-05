#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

//https://stackoverflow.com/questions/11310898/how-do-i-get-the-type-of-a-variable

int main()
{
    int *i1, *i2; //put one * per pointer
    int* i3, i4; //i3 will be treated as pointer, but i4 not
    float f1;
    double d1;
    std::string s1;

    cout << typeid(i1).name() << endl; //Pi
    cout << typeid(i2).name() << endl; //Pi
    cout << typeid(i3).name() << endl; //Pi
    cout << typeid(i4).name() << endl; //i
    cout << typeid(f1).name() << endl; //f
    cout << typeid(d1).name() << endl; //d
    cout << typeid(s1).name() << endl; //NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    
    return 0;
}
