#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//https://stackoverflow.com/questions/4346010/copy-stdstack-into-an-stdvector
int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(4);
    stk.push(9);
    stk.push(3);
    
    int* end   = &stk.top() + 1;
    int* begin = end - stk.size();
    vector<int> stack_contents(begin, end);
    
    //1 4 9 3
    for(int e : stack_contents){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
