#include <iostream>

enum class Fruit{
    APPLE = 0,
    BANANA,
    COCONUT,
    DURIAN
};

enum class Vehicle : uint8_t {
    CAR = 0,
    AIRPLANE,
    SHIP
};

template <typename E>
constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
    return static_cast<typename std::underlying_type<E>::type>(e);
};

int main() {
    std::cout << "Fruit::COCONUT's underlying value: " << to_underlying(Fruit::COCONUT)
      << ", underlying type: " << typeid(to_underlying(Fruit::COCONUT)).name() << std::endl;
    std::cout << "Vehicle::AIRPLANE's underlying value: " << to_underlying(Vehicle::AIRPLANE)
      << ", underlying type: " << typeid(to_underlying(Vehicle::AIRPLANE)).name() << std::endl;
    //Fruit::COCONUT's underlying value: 2
    return 0;
}

/**
Fruit::COCONUT's underlying value: 2, underlying type: i
Vehicle::AIRPLANE's underlying value: , underlying type: h
**/
