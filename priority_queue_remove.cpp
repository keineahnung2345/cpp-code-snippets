#include <iostream>
#include <queue> //priority_queue
#include <algorithm> //find

//https://stackoverflow.com/questions/19467485/how-to-remove-element-not-at-top-from-priority-queue

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>{
public:
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       } else {
            return false;
       }
    }
};

int main() {
    custom_priority_queue<int> pq;
    
    pq.push(10);
    pq.push(2);
    pq.push(4);
    pq.push(6);
    pq.push(3);

    pq.remove(6);

    while (!pq.empty()) {
        std::cout << pq.top();
        pq.pop();
        
        if (!pq.empty()){
            std::cout << ", ";
        }
    }
    
    return 0;
}

//10, 4, 3, 2
