#include <iostream>
#include <vector>
#include <set>
#include <algorithm> //set_symmetric_difference
#include <iterator> //ostream_iterator

using namespace std;

int main() {
    set<string> sA = {"a", "b", "c"};
    set<string> sB = {"a", "d", "e", "f"};
    set<string> result;
    set_symmetric_difference(sA.begin(), sA.end(), 
                                 sB.begin(), sB.end(),
                                 inserter(result, result.begin()));
                                 
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
}
