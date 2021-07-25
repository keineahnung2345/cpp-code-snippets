#include <vector>
#include <string>
#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/21399820/how-do-i-get-the-type-of-the-elements-in-a-vector

class Dummy {

};

int main(int argc, char** argv) {
    vector<int> vi;
    decltype(vi)::value_type varInt;
    vector<Dummy*> vd;
    decltype(vd)::value_type varDummy;

    if (typeid(varInt) == typeid(int))
        cout << "type is int" << endl;
    else
        cout << "type is " << typeid(varInt).name() << endl;

    if (typeid(varDummy) == typeid(Dummy*))
        cout << "type is Dummy*" << endl;
    else
        cout << "type is " << typeid(varDummy).name() << endl;

    return 0;
}

/**
type is int
type is Dummy*
**/
