#include <iostream>
#include <string>
#include <vector>

//https://www.geeksforgeeks.org/delete-this-in-c/

class A{
public:
    void fun(){
        delete this;
    }
};

class B{
private:
    int x;
    std::string s;
    std::vector<int> v;
public:
    B(){
        x = 100;
        s = "abc";
        v.push_back(x);
    }

    void fun(){
        std::cout << "before delete this" << std::endl;
        std::cout << x << std::endl;
        std::cout << s << std::endl;
        std::cout << v.size() << " " << v[0] << std::endl;

        delete this;

        /* Invalid: Undefined Behavior */
        std::cout << "after delete this" << std::endl;
        std::cout << x << std::endl;
        std::cout << s << std::endl;
        std::cout << v.size() << " " << v[0] << std::endl;
    }
};


int main(){
    /* Following is Valid */
    A *ptr1 = new A;
    ptr1->fun();
    ptr1 = nullptr; // make ptr NULL to make sure that things are not accessed using ptr.

    /* Following is Invalid: Undefined Behavior */
    /*
    a.out(24779,0x1164e25c0) malloc: *** error for object 0x7ffee89ff718: pointer being freed was not allocated
    a.out(24779,0x1164e25c0) malloc: *** set a breakpoint in malloc_error_break to debug
    Abort trap: 6
    */
    /*
    A a;
    a.fun();
    */

    B *ptr2 = new B;
    ptr2->fun();
    ptr2 = nullptr;
    return 0;
}

/*
before delete this
100
abc
1 100
after delete this
100
abc
0 0
*/
