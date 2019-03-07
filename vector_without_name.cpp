#include <iostream>
#include <vector>

using namespace std;

int main() {
    //http://www.cplusplus.com/forum/beginner/158913/
    for(auto e : vector<string> {"a", "b", "c"}){
        cout << e << " ";
    }
    cout << endl;
}

