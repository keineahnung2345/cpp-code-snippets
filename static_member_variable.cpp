#include <vector>
#include <string>
#include <iostream>

//https://www.learncpp.com/cpp-tutorial/static-member-variables/

using namespace std;

class Visitor {
private:
    static int count; // this only "declares" the variable!

public:
    Visitor() { ++count; }
    static int get() { return count; }
};

int Visitor::count = 10; // actually "defines" the variable

int main(int argc, char** argv) {
    Visitor v1;
    cout << Visitor::get() << endl; // 11
    Visitor v2;
    cout << Visitor::get() << endl; // 12

    return 0;
}
