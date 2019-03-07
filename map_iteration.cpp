#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    
    m['a'] = 2;
    m['b'] = 5;
    m['c'] = 8;

    //https://stackoverflow.com/questions/1063453/how-to-display-map-contents
    for (const auto &p : m) {
        std::cout << "m[" << p.first << "] = " << p.second << '\n';
    }

    return 0;
}

