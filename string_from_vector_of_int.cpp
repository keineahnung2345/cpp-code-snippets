#include <iostream>
#include <vector>
#include <sstream> //stringstream
#include <iterator> //ostream_iterator
#include <algorithm> //copy

using namespace std;

//https://stackoverflow.com/questions/2518979/how-to-transform-a-vectorint-into-a-string

int main() {
    vector<int> vec = {0, 1, 0};
    stringstream result;
    copy(vec.begin(), vec.end(), ostream_iterator<int>(result, ""));
    cout << result.str() << endl;
    return 0;
}

//010
