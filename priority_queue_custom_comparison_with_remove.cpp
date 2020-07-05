#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/58224722/c-priority-queue-with-custom-comparator-and-removal-of-any-item

class compare_height{
public:
    compare_height(){}
    bool operator() (const vector<int>& b1, const vector<int>& b2) const{
        return b1[2] < b2[2];
    }
};

//equip the original priority_queue with "remove"
template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, compare_height>{
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

int main(){
    //building with larger height will be put on top
    auto comp = [](const vector<int>& b1, const vector<int>& b2){
        return b1[2] < b2[2];
    };
    
    /*
    the template parameter is that for 
    template<typename T> class custom_priority_queue,
    not for template <class T, class Container = vector<T>,
    class Compare = less<typename Container::value_type> > class priority_queue!
    */
    custom_priority_queue<vector<int>> pq;
    
    vector<vector<int>> buildings = {
        {1, 3, 10},
        {2, 4, 5},
        {3, 5, 6},
        {4, 7, 9}
    };
    
    for(vector<int>& building : buildings){
        pq.push(building);
    }
    
    pq.remove({3, 5, 6});
    
    while(!pq.empty()){
        vector<int> building = pq.top();
        cout << building[0] << ", " << building[1] << ", " << building[2] << endl;
        pq.pop();
    }
        
    return 0;
};
