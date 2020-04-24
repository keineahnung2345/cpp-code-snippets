#include <map>
#include <vector>
#include <algorithm> //transform
#include <iostream>
#include <string>
#include <iterator> //ostream_iterator, back_inserter

#define LAMBDA

using namespace std;

struct RetrieveKey
{   
    template <typename T>
    typename T::first_type operator()(T keyValuePair) const
    {   
        return keyValuePair.first;
    }
};

struct RetrieveValue
{   
    template <typename T>
    typename T::second_type operator()(T keyValuePair) const
    {   
        return keyValuePair.second;
    }
};

//https://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap-and-put-them-into-a-vector
//https://stackoverflow.com/questions/771453/copy-map-values-to-vector-in-stl

int main()
{
    map<int, std::string> mymap;
    vector<int> keys;
    vector<std::string> values;

    mymap[10] = "convert";
    mymap[20] = "map";
    mymap[30] = "to";
    mymap[40] = "vector";

#ifdef LAMBDA
    //using lambda
    //must be "const" int!

    // Retrieve all keys
    std::transform(mymap.begin(), mymap.end(), std::back_inserter(keys), [](std::pair<const int, std::string>& p){return p.first;});
    
    // Retrieve all values
    std::transform(mymap.begin(), mymap.end(), std::back_inserter(values), [](std::pair<const int, std::string>& p){return p.second;});
    
    // Dump all keys
    std::transform(mymap.begin(), mymap.end(), std::ostream_iterator<int>( std::cout, " " ), [](std::pair<const int, std::string>& p){return p.first;});
    std::cout << std::endl;

    // Dump all values
    std::transform(mymap.begin(), mymap.end(), std::ostream_iterator<std::string>( std::cout, " " ), [](std::pair<const int, std::string>& p){return p.second;});
    std::cout << std::endl;

#else
    // Retrieve all keys
    std::transform(mymap.begin(), mymap.end(), std::back_inserter(keys), RetrieveKey());

    // Retrieve all values
    std::transform(mymap.begin(), mymap.end(), std::back_inserter(values), RetrieveValue());

    // Dump all keys
    std::copy(keys.begin(), keys.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Dump all values
    std::copy(values.begin(), values.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
#endif

}

/*
10 20 30 40 
convert map to vector
*/
