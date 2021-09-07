#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function

class Father{
public:
    void print(){ std::cout << "father" << std::endl;}
};

class Mother{
public:
    void print(){ std::cout << "mother" << std::endl;}
};

class Child : public Father, public Mother{
public:
    void print(){
        std::cout << "call Father::print" << std::endl;
        Father::print();
        std::cout << "call Mother::print" << std::endl;
        Mother::print();
        std::cout << "child" << std::endl;
    }
};

int main() {
    Child c;
    c.print();
    return 0;
}

/**
call Father::print
father
call Mother::print
mother
child
call Father::print
father
call Mother::print
mother
child
**/
