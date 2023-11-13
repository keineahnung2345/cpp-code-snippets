#include <iostream>
#include <tuple>

// https://stackoverflow.com/questions/2687392/is-it-possible-to-declare-two-variables-of-different-types-in-a-for-loop

int main() {
    for (auto [i, f, s] = std::tuple{1, 1.0, std::string{"ab"}}; i < 3; ++i, f += 1.5, s += (char)(97+i)) {
        std::cout << i << ", " << f << ", " << s << std::endl;
    }

    return 0;
}

/**
1, 1, ab
2, 2.5, abc
**/
