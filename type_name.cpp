/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

using namespace std;

//https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
//C++11 solution
template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
    (
    #ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr,
            nullptr, nullptr),
    #else
        nullptr,
    #endif
        std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

int main()
{
    char c = 'c';
    //method1: output "Ss"
    cout << typeid(string(1, c)).name() << endl;
    //method2: output "std::string"
    cout << type_name<decltype(string(1, c))>() << endl;
    return 0;
}
