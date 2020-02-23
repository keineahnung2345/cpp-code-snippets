#include <iostream>
#include <vector>

//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

void combinationUtil(std::vector<int>& arr, std::vector<int>& combination, std::vector<std::vector<int>>& combinations, int start, int end, int index, int r) { 
    if (index == r) { 
        combinations.push_back(combination);
        return;
    }

    //r - index : number of remaining cells in "combination" to be filled
    //end - i + 1 : the size of remaining cells in "arr"
    //stop when we don't have enough elements to fill the remaining part of "combination"
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        combination[index] = arr[i];
        combinationUtil(arr, combination, combinations, i+1, end, index+1, r);
    } 
} 

void getCombinations(std::vector<int>& arr, std::vector<std::vector<int>>& combinations, int n, int r) {
    std::vector<int> combination(r);
    combinationUtil(arr, combination, combinations, 0, n-1, 0, r); 
} 

int main() { 
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> combinations;
    int r = 3; 
    int n = arr.size();
    getCombinations(arr, combinations, n, r);
    for(std::vector<int>& combination : combinations) {
        std::copy(combination.begin(), combination.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
} 

/*
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5
*/
