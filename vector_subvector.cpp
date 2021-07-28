#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector

using namespace std;

int main()
{
    vector<int> myvec = {1,2,3,4,5,6,7,8,9};
    // note that endIter cannot be omitted
    vector<int> mysubvec(myvec.begin()+3, myvec.begin()+5);
    
    for(int& e : mysubvec){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

//4 5
