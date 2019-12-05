#include <iostream>
#include <assert.h>

//https://stackoverflow.com/questions/3692954/add-custom-messages-in-assert

int main(){
    int a = 1, b = 0;
    //assert(a == b && "A is not equal to B");
    //a.out: assert_message.cpp:6: int main(): Assertion `a == b && "A is not equal to B"' failed.
    //Aborted (core dumped)
    
    assert(("A must be equal to B", a == b));
    //a.out: assert_message.cpp:7: int main(): Assertion `("A must be equal to B", a == b)' failed.
    //Aborted (core dumped)
    return 0;
}
