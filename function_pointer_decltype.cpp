#include <functional>
#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// https://www.geeksforgeeks.org/function-pointer-in-c/
// https://stackoverflow.com/questions/32887979/get-decltype-of-function
/**
 * decltype(add) has type int(int, int),
 * which is not a function pointer.
 * To create a function pointer,
 * either feed the function's address into decltype,
 * or add * after decltype to make it a pointer
 */

int main() {
    // all work
    // std::vector<int (*)(int, int)>            functions = { add, multiply };
    // std::vector<decltype(&add)>               functions = { add, multiply };
    // std::vector<decltype(add)*>               functions = { add, multiply };
    // std::vector<std::function<int(int, int)>> functions = { add, multiply };
    std::vector<std::function<decltype(add)>> functions = { add, multiply };
    for(auto f : functions) {
        std::cout << f(1, 2) << std::endl;
    }
}

/**
3
2
*/
