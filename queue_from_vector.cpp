#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//https://stackoverflow.com/questions/8168127/how-can-i-copy-an-entire-vector-into-a-queue

int main() {
    vector<int> myvec = {3,7,1,9,2,8,0};
    queue<int, deque<int>> q(deque<int>(myvec.begin(), myvec.end()));
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
