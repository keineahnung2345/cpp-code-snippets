#include <iostream>
#include <vector>
#include <algorithm> //upper_bound, lower_bound

using namespace std;

//https://stackoverflow.com/questions/17711652/lower-bound-of-vector-of-pairs-with-lambda

int main() {
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
	
    cout << "upper_bound(the largest number <= x)" << endl;
    for(int tosearch : tosearches){
        auto it = upper_bound(myvec.begin(), myvec.end(), tosearch);
        if(it == myvec.begin()){
            cout << "cannot find number smaller or equal to " << tosearch << endl;
        }else{
        	/*
        	it points to the first element > x,
        	prev(it) points to the last element <= x!!
        	*/
        	it = prev(it); //!!!
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
            cout << "cannot find number larger than or equal to " << tosearch << endl;
        }else{
            cout << tosearch << " " << (it-myvec.begin()) << endl;
        }
    }
    cout << endl;
	
    cout << endl << "finding in ..." << endl;
    for(int e : myvec){
        cout << e << " ";
    }
    cout << endl;
	
    cout << "lower_bound(the largest number < x)..." << endl;
    for(int tosearch : tosearches){
        auto it = lower_bound(myvec.begin(), myvec.end(), tosearch);
        if(it == myvec.begin()){
            cout << "cannot find number smaller than " << tosearch << endl;
        }else{
        	it = prev(it);
            cout << tosearch << " " << (it-myvec.begin()) << endl;
        }
    }
    cout << endl;
    
    cout << "demo of lower_bound with custom comparison function..." << endl;
    vector<vector<int>> intervals = {{1,5}, {3,6}, {2,4}, {4, 7}, {5,5}};
    sort(intervals.begin(), intervals.end());
    
    cout << "finding in ..." << endl;
    for(vector<int>& interval : intervals){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    vector<int> dummy = {3, -1}; //second element is meaningless
    auto it = lower_bound(intervals.begin(), intervals.end(), dummy,
        [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
            });
    if(it == intervals.end()){
        cout << "cannot find interval whose end larger than or equal to " << dummy[0] << endl;
    }else{
        cout << "found an interval whose starting point >= " << dummy[0] << " at " << (it-intervals.begin()) << endl;
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
upper_bound(the largest number <= x)
cannot find number smaller or equal to -2
4 3
5 3
11 6

finding in ...
-1 2 3 4 6 9 10 
lower_bound(the smallest number >= x)...
-2 0
4 3
5 4
cannot find number larger than or equal to 11


finding in ...
-1 2 3 4 6 9 10 
lower_bound(the largest number < x)...
cannot find number smaller than -2
4 2
5 3
11 6

demo of lower_bound with custom comparison function...
finding in ...
[1, 5] [2, 4] [3, 6] [4, 7] [5, 5] 
found an interval whose starting point >= 3 at 2
*/
