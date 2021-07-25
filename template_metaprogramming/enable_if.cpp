#include <vector>
#include <string>
#include <iostream>

//https://stackoverflow.com/questions/12160765/if-else-at-compile-time-in-c

using namespace std;

class Dummy {
public:
    int fun1(string s, vector<vector<float>> vvf) { return 0; };
    int fun2(char c) { return 0; };
};

template <class R, class C, class... Args>
typename std::enable_if<sizeof...(Args) >= 2, std::string>::type
get2ndArgType(R(C::*)(Args...)) {
    return typeid(std::remove_reference<std::tuple_element_t<1, std::tuple<Args...>>>::type).name();
}

template <class R, class C, class... Args>
typename std::enable_if<sizeof...(Args) < 2, std::string> ::type
get2ndArgType(R(C::*)(Args...)) {
    return "it has less than 2 arguments!";
}

int main(int argc, char** argv) {
    cout << "fun1 2nd arg type: " << get2ndArgType(&Dummy::fun1) << endl;
    //fun1 2nd arg type: class std::vector<class std::vector<float,class std::allocator<float> >,class std::allocator<class std::vector<float,class std::allocator<float> > > >
    
    cout << "fun2 2nd arg type: " << get2ndArgType(&Dummy::fun2) << endl; //fun2 2nd arg type : it has less than 2 arguments!

    return 0;
}
