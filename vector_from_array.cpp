#include <iostream>
#include <iterator>
#include <vector>

// https://stackoverflow.com/questions/8777603/what-is-the-simplest-way-to-convert-array-to-vector

int main() {
    char buffer[30];
    scanf(buffer, "%s");
    std::vector<char> chars(std::begin(buffer), std::end(buffer));
    std::cout << chars.size() << std::endl;  // 30
    return 0;
}
