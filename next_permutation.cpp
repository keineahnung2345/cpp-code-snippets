#include <iostream>
#include <vector>
#include <algorithm> // sort, next_permutation

using namespace std;

int main()
{
    vector<int> myvec = {1,8,4};
    
    sort(myvec.begin(), myvec.end());
    
    do{
        for(int& e : myvec){
            cout << e << " ";
        }
        cout << endl;
    }while(next_permutation(myvec.begin(), myvec.end()));

    return 0;
}

/*
1 4 8 
1 8 4 
4 1 8 
4 8 1 
8 1 4 
8 4 1 
*/
