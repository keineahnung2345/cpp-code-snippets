#include <iostream>

//move constructor
//https://stackoverflow.com/a/25123890/10651567

/*
calling a function by value means we need to create a new object,
so copy constructor or move constructor will be called
*/
//https://stackoverflow.com/questions/16728441/why-copy-constructor-is-call-when-we-pass-an-object-as-an-argument-by-value-to-a

class A
{
public:
    int a;
    int b;
    A(){
        std::cout << "default ctor" << std::endl;
    }

    A(A&& other) : a{std::move(other.a)}, b{std::move(other.b)}{
        std::cout << "move ctor" << std::endl;
    }

    A(A& other) : a{other.a}, b{other.b}{
        std::cout << "copy ctor" << std::endl;
    }
};

void f1(A *a){
};

void f2(A a){
};

void f3(A &a){
};

void f4(A&& a){
};

int main(){
    A objA;

    std::cout << "f1" << std::endl;
    f1(&objA);
    std::cout << "f2 - lvalue" << std::endl;
    f2(objA);
    std::cout << "f2 - rvalue" << std::endl;
    f2(std::move(objA));
    std::cout << "f3" << std::endl;
    f3(objA);

    return 0;
}

/*
default ctor
f1
f2 - lvalue
copy ctor
f2 - rvalue
move ctor
f3
*/
