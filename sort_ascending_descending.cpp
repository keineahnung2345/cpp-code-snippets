#include <iostream>
#include <iostream>
#include <vector>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <iterator>     // std::ostream_iterator
 
int main() {
    std::vector<int> myvec = {0, 5, 2, 8, 12, 9, 3};
 
    //ascending
    // std::sort(myvec.begin(), myvec.end(), std::less<int>());
    std::sort(myvec.begin(), myvec.end());
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
 
    //descending
    // std::sort(myvec.begin(), myvec.end(), std::greater<int>());
    std::sort(myvec.rbegin(), myvec.rend());
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
 
 
	//For vector of pairs
    std::vector<std::pair<int, int>> myvec2 = {{0,2}, {3,1}, {4,5}, {1, 4}, {0,3}};
    //ascending
    // std::sort(myvec2.begin(), myvec2.end(), std::less<std::pair<int, int>>());
    std::sort(myvec2.begin(), myvec2.end());
    for(int i = 0; i < myvec2.size(); i++){
    	std::cout << "(" << myvec2[i].first << " " << myvec2[i].second << ") ";
    }
    std::cout << std::endl;
 
    //descending
    // std::sort(myvec2.begin(), myvec2.end(), std::greater<std::pair<int, int>>());
    std::sort(myvec2.rbegin(), myvec2.rend());
    for(int i = 0; i < myvec2.size(); i++){
    	std::cout << "(" << myvec2[i].first << " " << myvec2[i].second << ") ";
    }
    std::cout << std::endl;
	return 0;
}

/*
0 2 3 5 8 9 12 
12 9 8 5 3 2 0 
(0 2) (0 3) (1 4) (3 1) (4 5) 
(4 5) (3 1) (1 4) (0 3) (0 2) 
*/
