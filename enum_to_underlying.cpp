#include <iostream>

enum class Fruit{
    APPLE = 0,
    BANANA,
    COCONUT,
    DURIAN
};

template <typename E>
constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
    return static_cast<typename std::underlying_type<E>::type>(e);
};

int main() {
    std::cout << "Fruit::COCONUT's underlying value: " << to_underlying(Fruit::COCONUT) << std::endl;
    //Fruit::COCONUT's underlying value: 2
    return 0;
}
