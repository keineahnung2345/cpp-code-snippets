#include <iostream>
#include <vector>
#include <map>
#include <algorithm> //transform
#include <iterator> //ostream_iterator, back_inserter

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

int main()
{
    map<int, int> m;
    vector<int> keys, values;

    m[10] = 3;
    m[20] = 4;
    m[30] = 8;
    m[40] = 1;
    m[50] = 2;

    // Retrieve all keys
    std::transform(m.begin(), m.end(), std::back_inserter(keys), RetrieveKey());

    // Retrieve all values
    std::transform(m.begin(), m.end(), std::back_inserter(values), RetrieveValue());

    // Dump all keys
    std::copy(keys.begin(), keys.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Dump all keys
    std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

/*
10 20 30 40 50
3 4 8 1 2
*/
