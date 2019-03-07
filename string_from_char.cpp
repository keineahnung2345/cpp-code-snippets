#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    char c = 'c';
    //method1: output "Ss"
    cout << typeid(string(1, c)).name() << endl;
    return 0;
}
