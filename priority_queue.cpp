#include <iostream>
#include <queue> //priority_queue
#include <vector>

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

    std::vector<int> v = {1,7,2,9,3,0,4,5};

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;

    for(int e : v){
        pq1.push(e);
    }

    while(!pq1.empty()){
        std::cout << pq1.top() << " ";
        pq1.pop();
    }
    std::cout << std::endl;

    std::priority_queue<int, std::vector<int>, std::less<int>> pq2;

    for(int e : v){
        pq2.push(e);
    }

    while(!pq2.empty()){
        std::cout << pq2.top() << " ";
        pq2.pop();
    }
    std::cout << std::endl;

    return 0;
}

/*
0 1 2 3 4 5 7 9
9 7 5 4 3 2 1 0
*/
