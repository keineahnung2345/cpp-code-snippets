#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<string> s = {"a", "b", "c"};
    for(auto e : vector<string> (s.begin(), s.end())){
        cout << e << " ";
    }
}
