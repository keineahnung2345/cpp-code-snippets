#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

//https://stackoverflow.com/questions/2874441/deleting-elements-from-stdset-while-iterating

int main()
{
    set<int> os = {1,2,3,4,5,6};
    unordered_set<int> us = {1,2,3,4,5,6};
    
    for(auto it = os.begin(); it != os.end(); ){
        if((*it)&1){
            it = os.erase(it);
        }else{
            ++it;
        }
    }
    
    for(auto it = us.begin(); it != us.end(); ){
        if((*it)&1){
            it = us.erase(it);
        }else{
            ++it;
        }
    }
    
    for(const int& e : os){
        cout << e << " ";
    }
    cout << endl;
    
    for(const int& e : us){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

//2 4 6
//6 4 2
