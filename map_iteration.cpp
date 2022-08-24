#include <iostream>
#include <map>

int main() {
    std::map<char, int> m;

    m['a'] = 2;
    m['b'] = 5;
    m['c'] = 8;

    // Method 1
    // https://stackoverflow.com/questions/1063453/how-to-display-map-contents
    for(const auto &p : m) {
        std::cout << "m[" << p.first << "] = " << p.second << '\n';
    }

    // Method 2
    // https://stackoverflow.com/questions/1443793/iterate-keys-in-a-c-map
    for(const auto &[key, value] : m) {
        std::cout << "m[" << key << "] = " << value << '\n';
    }

    return 0;
}
