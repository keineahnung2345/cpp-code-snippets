#include <iostream>
#include <memory> //std::shared_ptr

/**
this program demos the usage of "typename" keyword
"typename" is needed to be added for qualified name when template argument is unsure
**/

//[C++ Cast Template](https://stackoverflow.com/questions/37983562/c-cast-template)
//[Where and why do I have to put the “template” and “typename” keywords?](https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords)
//[Qualified name lookup](https://en.cppreference.com/w/cpp/language/qualified_lookup)

template<typename T>
class Animal{
public:
    using Ptr = std::shared_ptr< Animal< T > >;
};

template<typename T>
void f(){
    Animal<T> a;

    //error: need ‘typename’ before ‘Animal<T>::Ptr’ because ‘Animal<T>’ is a dependent scope
    //error: expected ‘;’ before ‘ap’
    //Animal<T>::Ptr ap;

    //correct
    typename Animal<T>::Ptr ap;
}

int main(){
    //ok
    Animal<int> a;
    //when template argument is concrete, we don't need to add "typename"
    Animal<int>::Ptr ap;
    return 0;
}
