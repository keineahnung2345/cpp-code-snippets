#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myvec;
    for (int i = 0; i < 10; i++)
        myvec.push_back(i);

    for(vector<int>::iterator it=myvec.begin();it!=myvec.end();it++){
        cout << *it << " ";
    }
    cout << endl;

    for(vector<int>::reverse_iterator it=myvec.rbegin();it!=myvec.rend();it++){
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
