#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> ans(3, vector<int>(5));
    cout << ans.size() << ", " << ans[0].size() << endl;
    for(vector<int> v : ans){
        for(int e : v){
            cout << e << " ";
        }
        cout << endl;
    }
}
