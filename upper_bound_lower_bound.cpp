#include <iostream>
#include <vector>
#include <algorithm> //upper_bound, lower_

using namespace std;

int main() {
    // your code goes here
    vector<int> myvec = {-1,2,3,4,6,9,10};
    vector<int> tosearches = {-2,4,5,11};
	
    cout << "finding in ..." << endl;
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
	
    cout << "upper_bound(the smallest number > x)" << endl;
    for(int tosearch : tosearches){
        auto it = upper_bound(myvec.begin(), myvec.end(), tosearch);
        if(it == myvec.end()){
            cout << "cannot find number larger than " << tosearch << endl;
        }else{
            cout << tosearch << " " << (it-myvec.begin()) << endl;
        }
    }
	
    cout << endl << "finding in ..." << endl;
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
	
    cout << "lower_bound(the smallest number >= x)..." << endl;
    for(int tosearch : tosearches){
        auto it = lower_bound(myvec.begin(), myvec.end(), tosearch);
        if(it == myvec.end()){
            cout << "cannot find number larger than " << tosearch << endl;
        }else{
            cout << tosearch << " " << (it-myvec.begin()) << endl;
        }
    }
    return 0;
}

/*
finding in ...
-1 2 3 4 6 9 10 
upper_bound(the smallest number > x)
-2 0
4 4
5 4
cannot find number larger than 11

finding in ...
-1 2 3 4 6 9 10 
lower_bound(the smallest number >= x)...
-2 0
4 3
5 4
cannot find number larger than 11
*/
