#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/6906521/how-to-check-whether-a-vector-is-a-subset-of-another-in-c
//https://en.cppreference.com/w/cpp/algorithm/includes

template <typename T>
bool IsSubset(std::vector<T> A, std::vector<T> B){
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    return std::includes(A.begin(), A.end(), B.begin(), B.end());
}

int main() {
    vector<vector<string>> favoriteCompanies = {
        {"leetcode","google","facebook"},
        {"google","microsoft"},
        {"google","facebook"},
        {"google"},
        {"amazon"}
    };
    
    bool included = std::includes(favoriteCompanies[0].begin(), favoriteCompanies[0].end(),
                  favoriteCompanies[2].begin(), favoriteCompanies[2].end());
    
    cout << "std::includes?: " << included << endl;
    
    //before using std::includes, we need to sort the vectors!!
    included = IsSubset(favoriteCompanies[0], favoriteCompanies[2]);
    
    cout << "sort and then std::includes?: " << included << endl;
    
    return 0;
}
