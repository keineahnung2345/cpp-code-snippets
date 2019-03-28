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

//https://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap-and-put-them-into-a-vector

int main()
{
    map<int, int> m;
    vector<int> keys;
    
    m[10] = 3;
    m[20] = 4;
    m[30] = 8;
    m[40] = 1;
    m[50] = 2;

    // Retrieve all keys
    transform(m.begin(), m.end(), back_inserter(keys), RetrieveKey());
    
    // Dump all keys
    copy(keys.begin(), keys.end(), ostream_iterator<int>(cout, "\n"));
}
