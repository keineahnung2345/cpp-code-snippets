#include <iostream>
#include <queue> //priority_queue
#include <vector>

using namespace std;

int main()
{
    //https://en.cppreference.com/w/cpp/container/priority_queue
    /**
    template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
    > class priority_queue;
    **/
    /**
    "Compare" returns true when a should be put before b
    so the order will be descending,
    but pq pop last element in the queue first,
    so when using pop, we will see ascending order
    **/
     
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v = {1,7,2,9,3,0,4,5};
    
    for(int e : v){
        pq.push(e);
    }
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
