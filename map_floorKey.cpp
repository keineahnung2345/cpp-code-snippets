#include <iostream>
#include <map>

//https://stackoverflow.com/questions/23043936/using-template-iterator-in-c-stdmap
template<typename Key, typename Value>
using MapIterator = typename std::map<Key,Value>::const_iterator;

//https://codereview.stackexchange.com/questions/222587/java-treemap-floorkey-equivalent-for-stdmap
template<typename Key, typename Value>
Key floorKey(const std::map<Key,Value>& input, const Key& key){
    /*
    map::upper_bound : 
    Returns an iterator pointing to the first element in the container 
    whose key is considered to go after k.
    
    If k is larger than any key in the map, then it returns map::end
    */
    MapIterator<Key, Value> it = input.upper_bound(key);
    if (it != input.begin()) {
        return (--it)->first;
    } else {
        //assume Key is int
        return -1;
    }
}

int main() {
    std::map<int, int> map =
    {
        { 10, 100 },
        { 20, 200 },
        { 30, 300 },
        { 40, 400 },
        { 50, 500 },
        { 60, 600 },
        { 70, 700 },
        { 80, 800 },
    };

    std::cout << floorKey(map, 5) << std::endl
              << floorKey(map, 9) << std::endl
              << floorKey(map, 10) << std::endl
              << floorKey(map, 11) << std::endl
              << floorKey(map, 90) << std::endl;
}

/*
-1
-1
10
10
80
*/
