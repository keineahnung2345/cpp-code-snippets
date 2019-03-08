#include <iostream>
#include <map>

using namespace std;

template <class K, class V>
void insert_or_increment(map<K,V>& mymap, K key, V inc){
    if(mymap.find(key)==mymap.end()){
        mymap[key] = 0+inc;
    }else{
        mymap[key] += inc;
    }
}

int main() {
    map<char, int> mymap;
    
    mymap['a'] = 3;
    mymap['b'] = 0;
    mymap['c'] = 9;
    
    insert_or_increment(mymap, 'c', 1);
    insert_or_increment(mymap, 'd', 1);
    
    for(auto elem : mymap){
        cout << "{" << elem.first << " " << elem.second << "} ";
    }
    cout << endl;
}
