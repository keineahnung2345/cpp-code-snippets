#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

#include <boost/function.hpp>
#include <boost/function_types/function_type.hpp>
#include <boost/function_types/function_arity.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/typeof/typeof.hpp>

using namespace std;

//https://stackoverflow.com/questions/2165030/use-boost-to-get-arity-and-paramerter-types-of-member-function-boostfunction

class Dummy {
public:
    int fun1(string s, vector<vector<float>> vvf) { return 0; };
};

double myfun(char c){ return 0.0; };

int main()
{
    vector<int> vi;
    decltype(vi)::value_type varInt;
    vector<Dummy*> vd;
    decltype(vd)::value_type varDummy;

    cout << "arity: " << boost::function_types::function_arity<BOOST_TYPEOF(&Dummy::fun1)>::value << endl;
    cout << "arg0: " << typeid(boost::mpl::at_c<boost::function_types::parameter_types<BOOST_TYPEOF(&Dummy::fun1)>, 0>::type).name() << endl;
    cout << "arg1: " << typeid(boost::mpl::at_c<boost::function_types::parameter_types<BOOST_TYPEOF(&Dummy::fun1)>, 1>::type).name() << endl;
    cout << "arg2: " << typeid(boost::mpl::at_c<boost::function_types::parameter_types<BOOST_TYPEOF(&Dummy::fun1)>, 2>::type).name() << endl;
    cout << "result_type: " << typeid(boost::function<decltype(&Dummy::fun1)()>::result_type).name() << endl;
    
    cout << endl;
    
    cout << "arity: " << boost::function_types::function_arity<BOOST_TYPEOF(&myfun)>::value << endl;
    cout << "arg0: " << typeid(boost::mpl::at_c<boost::function_types::parameter_types<BOOST_TYPEOF(&myfun)>, 0>::type).name() << endl;
    cout << "result_type: " << typeid(boost::function<decltype(&myfun)()>::result_type).name() << endl;
    
    return 0;
}

/**
arity: 3
arg0: 5Dummy
arg1: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
arg2: St6vectorIS_IfSaIfEESaIS1_EE
result_type: M5DummyFiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt6vectorIS6_IfSaIfEESaIS8_EEE

arity: 1
arg0: c
result_type: PFdcE
**/

/**
MSVC compiler
arity: 3
arg0: class Dummy
arg1: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
arg2: class std::vector<class std::vector<float,class std::allocator<float> >,class std::allocator<class std::vector<float,class std::allocator<float> > > >
result_type: int (__cdecl Dummy::*)(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::vector<class std::vector<float,class std::allocator<float> >,class std::allocator<class std::vector<float,class std::allocator<float> > > >) __ptr64

arity: 1
arg0: char
result_type: double (__cdecl*)(char)
**/
