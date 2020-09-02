#include <iostream>
#include <vector>

using namespace std;

//https://www.geeksforgeeks.org/calculate-ncr-using-pascals-triangle/

int main() {
    int max_num = 100;
    vector<vector<int>> pascal(max_num+1);
    
    //0C0 is 1
    pascal[0] = {1};
    
    for(int n = 1; n <= max_num; ++n){
        pascal[n] = vector<int>(n+1);
        //iC0 is 1
        pascal[n][0] = 1;
        for(int r = 1; r <= n; ++r){
            //nCr = (n-1)C(r-1) + (n-1)Cr
            pascal[n][r] = pascal[n-1][r-1] + pascal[n-1][r];
        }
    }
    
    cout << "5C3 : " << pascal[5][3] << endl; //5C3 : 10
    
    return 0;
}
