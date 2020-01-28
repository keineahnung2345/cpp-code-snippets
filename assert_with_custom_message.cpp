#include <iostream>
#include <assert.h>
#include <vector>

//https://stackoverflow.com/questions/3692954/add-custom-messages-in-assert

int main(){
    int a = 1, b = 0;
    //assert(a == b && "A is not equal to B");
    //a.out: assert_message.cpp:6: int main(): Assertion `a == b && "A is not equal to B"' failed.
    //Aborted (core dumped)

    //assert(("A must be equal to B", a == b));
    //a.out: assert_message.cpp:7: int main(): Assertion `("A must be equal to B", a == b)' failed.
    //Aborted (core dumped)

    //on Mac
    //Assertion failed: (0 && "vector index must in [0, v.size())"), function main, file assert.cpp, line 20.
    //Abort trap: 6
    std::vector<int> v = {1,2,3};
    int index = -1;
    if(index < 0 || index >= v.size()){
        assert(0 && "vector index must be in [0, v.size())");
    }
    return 0;
}
