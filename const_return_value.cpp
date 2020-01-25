#include <iostream>
#include <vector>

const int f1(){
    return 3;
};

const char* f2(){
    return "abc";
};

std::vector<int> myvec = {0};

const std::vector<int>& f3(){
    return myvec;
}

int main(){
    int x = f1();

    //error: cannot initialize a variable of type 'char *' with an rvalue of type 'const char *'
    //char* s = f2();
    const char* s = f2();

    //ok
    //std::vector<int> v = f3();
    //error: binding value of type 'const vector<...>' to reference to type 'vector<...>' drops 'const' qualifier
    //std::vector<int>& v = f3();
    //ok
    const std::vector<int>& v = f3();

    std::cout << "int: " << x << std::endl;
    std::cout << "const char*: " << s << std::endl;
    std::cout << "const vector&: " << v[0] << std::endl;

    x = 2;
    //error: read-only variable is not assignable
    //s[0] = 'd';
    std::cout << "int: " << x << std::endl;
    //error: cannot assign to return value because function 'operator[]' returns a const value
    //v[0] = 1;
    return 0;
}

/*
int: 3
const char*: abc
const vector&: 0
int: 2
*/
