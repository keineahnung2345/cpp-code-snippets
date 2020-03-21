#include <iostream>
#include <vector>
#include <set>
#include <algorithm> //set_symmetric_difference
#include <iterator> //ostream_iterator

using namespace std;

//https://stackoverflow.com/questions/16079362/how-to-compute-in-place-set-difference-of-two-multisets

int main() {
    set<string> sA = {"a", "b", "c"};
    set<string> sB = {"a", "d", "e", "f"};
    set<string> tmp;
    set_symmetric_difference(sA.begin(), sA.end(), 
                                 sB.begin(), sB.end(),
                                 inserter(tmp, tmp.begin()));
    //if we want the result to be stored in sA
    sA.swap(tmp);
                                 
    copy(sA.begin(), sA.end(), ostream_iterator<string>(cout, " "));
}

//b c d e f 
