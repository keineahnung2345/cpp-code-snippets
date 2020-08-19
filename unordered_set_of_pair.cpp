#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

//https://stackoverflow.com/questions/15160889/how-can-i-make-an-unordered-set-of-pairs-of-integers-in-c
struct pair_hash_int {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

//https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

int main() {
    set<pair<int, int>> s;
    s.insert({1,2});
    
    set<pair<string, int>> s2;
    s2.insert({"a", 1});
    
    // error: use of deleted function ‘std::unordered_set<_Value, _Hash, _Pred, _Alloc>::unordered_set() [with _Value = std::pair<int, int>; _Hash = std::hash<std::pair<int, int> >; _Pred = std::equal_to<std::pair<int, int> >; _Alloc = std::allocator<std::pair<int, int> >]’
    // unordered_set<pair<int, int>> us;
    
    //need to revise to:
    unordered_set<pair<int, int>, pair_hash_int> us;
    us.insert({1,2});
    
    unordered_set<pair<string, int>, pair_hash> us2;
    us2.insert({"a", 1});
    
    return 0;
}
