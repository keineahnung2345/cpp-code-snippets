#include <iostream>
#include <queue> //priority_queue
#include <vector>

using namespace std;

class mycomparison
{
public:
  mycomparison(){}
  bool operator() (const int& lhs, const int&rhs) const
  {
    return (abs(lhs)>abs(rhs));
  }
};

int main()
{
    priority_queue<int, vector<int>, mycomparison> pq;
    vector<int> v = {1,7,2,9,3,0,4,5,-3,-9,-4,-2};
    
    for(int e : v){
        pq.push(e);
    }
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    //0 1 2 -2 3 -3 4 -4 5 7 -9 9 
    return 0;
}
