#include <exception>
#include <iostream>
#include <vector>

void throwOutOfRangeException() {
    std::vector<int> v(3);
    v.at(3);
}

int main() {
    try {
        throwOutOfRangeException();
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
