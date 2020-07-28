#include <iostream>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/8628951/remove-elements-of-a-vector-inside-the-loop

int main() {
    vector<int> myvec = {3,6,2,9,5,1,0,7,4};
    
    for(vector<int>::iterator it = myvec.begin(); it != myvec.end(); ){
        if(*it < 5){
            myvec.erase(it);
        }else{
            ++it;
        }
    }
    
    for(int& e : myvec){
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}

//6 9 5 7 
