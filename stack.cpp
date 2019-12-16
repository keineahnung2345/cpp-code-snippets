#include <iostream>
#include <stack>

//https://www.geeksforgeeks.org/stack-in-cpp-stl/

int main(){
    std::stack<int> stk;
    stk.push(1);
    stk.push(9);
    stk.push(3);

    std::cout << "top: " << stk.top() << std::endl;
    while(!stk.empty()){
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}
