#include <iostream>
#include <map>

//https://stackoverflow.com/questions/23043936/using-template-iterator-in-c-stdmap
template<typename Key, typename Value>
using MapIterator = typename std::map<Key,Value>::const_iterator;

//https://codereview.stackexchange.com/questions/222587/java-treemap-floorkey-equivalent-for-stdmap
//The floorKey() method is used to return the greatest key less than or equal to given key from the parameter.
template<typename Key, typename Value>
Key floorKey(const std::map<Key,Value>& input, const Key& key){
    /*
    map::upper_bound(>): 
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

/*
The ceilingKey() function of TreeMap Class returns 
the least key greater than or equal to 
the given key or null if the such a key is absent.
*/
template<typename Key, typename Value>
Key ceilingKey(const std::map<Key,Value>& input, const Key& key){
	/*
	map::lower_bound(>=):
	Returns an iterator pointing to the first element 
	in the container whose key is not considered to go before k 
	(i.e., either it is equivalent or goes after).
	*/
    MapIterator<Key, Value> it = input.lower_bound(key);
    if (it != input.end()) {
        return it->first;
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

    std::cout << "floorKey" << std::endl;
    std::cout << floorKey(map, 5) << std::endl
              << floorKey(map, 9) << std::endl
              << floorKey(map, 10) << std::endl
              << floorKey(map, 11) << std::endl
              << floorKey(map, 90) << std::endl;

    std::cout << "ceilingKey" << std::endl;
    std::cout << ceilingKey(map, 5) << std::endl
              << ceilingKey(map, 9) << std::endl
              << ceilingKey(map, 10) << std::endl
              << ceilingKey(map, 11) << std::endl
              << ceilingKey(map, 90) << std::endl;
}

/*
floorKey
-1
-1
10
10
80
ceilingKey
10
10
10
20
-1
*/
