#include <iostream>

//https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c

enum class Fruit{
    APPLE = 0,
    BANANA,
    COCONUT,
    DURIAN
};

int main() {
    int i = 3;
    Fruit f = static_cast<Fruit>(i);
    return 0;
}
