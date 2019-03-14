#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
    bitset<5> b(20);
    cout << b << endl; //10010
    cout << b.count() << endl; //2
    cout << b[0] << endl; //0, index start from behind

    return 0;
}
