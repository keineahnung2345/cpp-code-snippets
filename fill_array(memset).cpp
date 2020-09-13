#include <iostream>
#include <cstring> //memset
#include <algorithm> //fill

using namespace std;

//https://stackoverflow.com/questions/3586774/fill-multidimensional-array-elements-with-0s
//https://stackoverflow.com/questions/9215210/how-to-memset-an-array-of-bools

int main() {
    int a[3][4][5];
    
    //memset not work for int!!
    // memset(a, 123, sizeof(a));
    
    //works
    fill(a[0][0], a[0][0]+3*4*5, 123);
    
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 5; ++k){
                cout << a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    char c[20];
    
    //memset works for char
    memset(c, '$', sizeof(c));
    
    //works
    // fill(begin(c), end(c), '$');
    
    for(int i = 0; i < 20; ++i){
        cout << c[i] << " ";
    }
    cout << endl;
    
    char b[20];
    
    //memset works for bool
    memset(b, true, sizeof(bool) * sizeof(b));
    
    //works
    // fill(begin(b), end(b), true);
    
    for(int i = 0; i < 20; ++i){
        cout << (b[i] ? '1' : '0') << " ";
    }
    cout << endl;
    
    return 0;
}
