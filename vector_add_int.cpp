#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/4461446/stl-way-to-add-a-constant-value-to-a-stdvector

int main() {
    int x = 5;
    vector<int> myvec = {1,2,3};
    for_each(myvec.begin(), myvec.end(), [&x](int& e) { e+=x;});
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
