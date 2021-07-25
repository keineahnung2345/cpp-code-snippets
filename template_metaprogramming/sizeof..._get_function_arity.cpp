#include <vector>
#include <string>
#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/3628364/count-of-parameters-in-a-parameter-pack-is-there-a-c0x-std-lib-function-for-t

double myfun(char c) { return 0.0; };
class Dummy {
public:
    int fun1(string s, vector<vector<float>> vvf) { return 0; };
};

template <class R, class... Args>
int argCount(R(* fun)(Args...)) {
    return sizeof...(Args);
};

template <class R, class C, class... Args>
int argCount(R(C::* fun)(Args...)) {
    return sizeof...(Args);
};

int main(int argc, char** argv) {
    cout << argCount(&myfun) << endl; //1
    cout << argCount(&Dummy::fun1) << endl; //2
    return 0;
}
