  
#include <iostream>
#include <queue> //priority_queue
#include <vector>
#include <unordered_map>

using namespace std;

class mycomparison{
public:
    mycomparison(){}
    bool operator() (const int& lhs, const int&rhs) const{
        return (abs(lhs)>abs(rhs));
    }
};

//https://stackoverflow.com/questions/5807735/c-priority-queue-with-lambda-comparator-error

int main(){
    /***Example 1***/
    priority_queue<int, vector<int>, mycomparison> pq;
    vector<int> v = {1,7,2,9,3,0,4,5,-3,-9,-4,-2};
    
    for(int e : v){
        pq.push(e);
    }
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    /***Example 2: capture varialbe in lambda function***/
    unordered_map<string, int> counter = 
    	{
    		{"a", 1},
    		{"aa",1},
    		{"aaa",1},
    		{"b",3},
    		{"c",2}
    	};
    
    //sort by their count, and then by lexicographical order
    auto comp = [&counter](const string& lhs, const string& rhs){
        /*if we want an element to be popped from priority queue earlier,
        then we need to make it rank lower in the sorted array
        */
        // cout << lhs << " " << counter[lhs] << " " << rhs << " " << counter[rhs] << endl;
        // cout << lhs << " " << rhs << " " << (lhs > rhs) << endl;
        return (counter[lhs] == counter[rhs]) ? (lhs > rhs) : 
            (counter[lhs] < counter[rhs]);
    };
    
    priority_queue<string , vector<string>, decltype(comp)> pq2(comp);
    
    for(auto it = counter.begin(); it != counter.end(); it++){
        pq2.push(it->first);
    }
    
    while(!pq2.empty()){
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;
        
    return 0;
}

/*
0 1 2 -2 3 -3 4 -4 5 7 -9 9 
b c a aa aaa 
*/
