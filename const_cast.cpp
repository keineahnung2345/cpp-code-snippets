#include <iostream>
#include <typeinfo>
#include <iomanip>

int add10(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

int main(void)
{
    int val = 10;
    const int val2 = 10;
    int* p;
    const int* pc;
    volatile int* pv;
    const volatile int* pcv;

    //error: const_cast to 'int', which is not a reference, pointer-to-object, or pointer-to-data-member
    //std::cout << const_cast<int>(val2) << std::endl;

    std::cout << "Experiment 1: " << std::endl;
    //cast away const/volatile keyword
    pc = &val;
    pv = &val;
    pcv = &val;
    std::cout << std::setw(35) << std::left << "typeid of const int* pc: " << typeid(pc).name() << "-->" << typeid(const_cast<int *>(pc)).name() << std::endl;
    std::cout << std::setw(35) << std::left << "typeid of volatile int* pv: " << typeid(pv).name() << "-->" << typeid(const_cast<int *>(pv)).name() << std::endl;
    std::cout << std::setw(35) << std::left << "typeid of const volatile int* pcv: " << typeid(pcv).name() << "-->" << typeid(const_cast<int *>(pcv)).name() << std::endl;

    //cast: add const/volatile keyword
    p = &val;
    std::cout << std::setw(35) << std::left << "cast to const int*: " << typeid(p).name() << "-->" << typeid(const_cast<const int *>(p)).name() << std::endl;
    std::cout << std::setw(35) << std::left << "cast to volatile int*: " << typeid(p).name() << "-->" << typeid(const_cast<volatile int *>(p)).name() << std::endl;
    std::cout << std::setw(35) << std::left << "cast to const volatile int*: " << typeid(p).name() << "-->" << typeid(const_cast<const volatile int *>(p)).name() << std::endl;

    std::cout << "\nExperiment 2: " << std::endl;
    val = 1000000;
    pc = &val;
    //error: const_cast from 'const int *' to 'char *' is not allowed
    //std::cout << *const_cast<char *>(pc) << std::endl;
    std::cout << (char *)(pc) << std::endl;

    std::cout << "\nExperiment 3: " << std::endl;
    val = 10;
    pc = &val;
    p = const_cast <int *>(pc);
    add10(p);
    std::cout << std::setw(35) << std::left << "try to add int 10 by 10: " << val << std::endl;

    pc = &val2;
    p = const_cast <int *>(pc);
    add10(p);
    std::cout << std::setw(35) << std::left << "try to add const int 10 by 10: " << val2 << std::endl;

    return 0;
}

/*
Experiment 1:
typeid of const int* pc:           PKi-->Pi
typeid of volatile int* pv:        PVi-->Pi
typeid of const volatile int* pcv: PVKi-->Pi
cast to const int*:                Pi-->PKi
cast to volatile int*:             Pi-->PVi
cast to const volatile int*:       Pi-->PVKi

Experiment 2:
@B

Experiment 3:
try to add int 10 by 10:           20
try to add const int 10 by 10:     10
*/
