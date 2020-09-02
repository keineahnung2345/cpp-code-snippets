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
        //we need nC0 to nCn
        pascal[n] = vector<int>(n+1);
        /*
        to calculate pascal[n][n], 
        it will use pascal[n-1][n], which doesn't exist,
        so here we treat pascal[n][n] as a special case
        and do not calculate it in the loop
        */
        //nC0 is 1
        pascal[n][0] = pascal[n][n] = 1;
        for(int r = 1; r < n; ++r){
            //nCr = (n-1)C(r-1) + (n-1)Cr
            //first term: comb count when choose first item
            //second term: comb count when not choose first item
            pascal[n][r] = pascal[n-1][r-1] + pascal[n-1][r];
        }
    }

    cout << "5C3 : " << pascal[5][3] << endl; //5C3 : 10

    return 0;
}
