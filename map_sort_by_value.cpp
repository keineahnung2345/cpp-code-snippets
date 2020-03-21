#include <iostream>
#include <map>
#include <utility> //pair
#include <algorithm> //transform

//https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p){
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src){
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

int main(void) {
    std::map<char, int> src = {{'a', 1}, {'b', 3}, {'c', 3}};

    std::multimap<int, char> dst = flip_map(src);
    // dst is now sorted by what used to be the value in src
    
    for(auto it = dst.begin(); it != dst.end(); it++){
    	std::cout << it->first << " " << it->second << std::endl;
    }
    
    return 0;
}
