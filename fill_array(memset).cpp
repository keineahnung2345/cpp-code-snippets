#include <iostream>
#include <cstring> //memset
#include <algorithm> //fill

using namespace std;

//https://stackoverflow.com/questions/3586774/fill-multidimensional-array-elements-with-0s

int main() {
    int a[3][4][5];
    
    //works
    //memset(a, -1, sizeof(a));
    
    //works
    fill(a[0][0], a[0][0]+3*4*5, -1);
    
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 5; ++k){
                cout << a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
