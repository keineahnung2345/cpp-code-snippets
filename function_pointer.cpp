#include <iostream>
  
int square(int x){
    return x * x;
}

//https://www.geeksforgeeks.org/function-pointer-in-c/

int main(){
    //use & and *
    int (*fnc_ptr)(int) = &square;
    std::cout << (*fnc_ptr)(10) << std::endl;

    //not using & and *
    int(*fnc_ptr2)(int) = square;
    std::cout << fnc_ptr2(10) << std::endl;

    //typedef
    typedef int(*MyFnc)(int);
    MyFnc f = square;
    std::cout << f(10) << std::endl;
  
    //function pointer as template argument
    std::unordered_map<std::string, MyFnc> mymap;
    mymap["square"] = square;
    std::cout << mymap["square"](10) << std::endl;
    return 0;
}

/*
100
100
100
100
*/
