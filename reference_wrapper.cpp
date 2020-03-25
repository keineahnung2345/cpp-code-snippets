#include <iostream>
#include <functional>   // std::ref

int main () {
    int foo (10);

    //auto bar = std::ref(foo);
    std::reference_wrapper<int> bar = std::ref(foo);
  
    ++bar;

    std::cout << foo << '\n';

    return 0;
}
