#include <iostream>
#include <algorithm> //copy_if
#include <vector>
 
using namespace std;
 
//https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container

int main() {
    vector<int> myvec = {1,2,3,4,5,6};
 
    vector<int> tmp;
    copy_if(myvec.begin(), myvec.end(), 
            back_inserter(tmp), 
            [](int& e){
                return e&1;} 
           );
    for(int& e : tmp){
        cout << e << " ";
    }
    cout << endl;
 
    return 0;
}

//1 3 5
