#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/11310898/how-do-i-get-the-type-of-a-variable

int main()
{
    int *i1, *i2; //put one * per pointer
    int* i3, i4; //i3 will be treated as pointer, but i4 not
    float f1;
    double d1;
    string s1;
    vector<int> vi;
    vector<vector<int>> vvi;
    vector<string> vs;

    cout << typeid(i1).name() << endl;  //Pi
    cout << typeid(i2).name() << endl;  //Pi
    cout << typeid(i3).name() << endl;  //Pi
    cout << typeid(i4).name() << endl;  //i
    cout << typeid(f1).name() << endl;  //f
    cout << typeid(d1).name() << endl;  //d
    cout << typeid(s1).name() << endl;  //NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    cout << typeid(vi).name() << endl;  //St6vectorIiSaIiEE
    cout << typeid(vvi).name() << endl; //St6vectorIS_IiSaIiEESaIS1_EE
    cout << typeid(vs).name() << endl;  //St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
    
    return 0;
}

/***
* result of MSVC compiler:
* int * __ptr64
* int * __ptr64
* int * __ptr64
* int
* float
* double
* class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
* class std::vector<int,class std::allocator<int> >
* class std::vector<class std::vector<int,class std::allocator<int> >,class std::allocator<class std::vector<int,class std::allocator<int> > > >
* class std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > >
**/
