#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

//https://stackoverflow.com/questions/15160889/how-can-i-make-an-unordered-set-of-pairs-of-integers-in-c

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int main() {
    set<pair<int, int>> s;
    s.insert({1,2});
    
    // error: use of deleted function ‘std::unordered_set<_Value, _Hash, _Pred, _Alloc>::unordered_set() [with _Value = std::pair<int, int>; _Hash = std::hash<std::pair<int, int> >; _Pred = std::equal_to<std::pair<int, int> >; _Alloc = std::allocator<std::pair<int, int> >]’
    // unordered_set<pair<int, int>> us;
    
    //need to revise to:
    unordered_set<pair<int, int>, pair_hash> us;
    us.insert({1,2});
    
    return 0;
}
