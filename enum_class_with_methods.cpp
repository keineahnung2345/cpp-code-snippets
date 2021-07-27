#include <vector>
#include <string>
#include <map>
#include <iostream>

/**
https://stackoverflow.com/a/53284026/10651567
this example use a class with enum member variable to mimic 
an enum class with methods
**/

using namespace std;

class Fruit {
public:
    static enum Value : int {
        APPLE = 0,
        BANANA,
        COCONUT
    };

    static void setupDefaultMsg() {
        defaultMsg[APPLE] = "It's red.";
        defaultMsg[BANANA] = "It's yellow.";
        defaultMsg[COCONUT] = "It's hard.";
    }

    Fruit(Value v = APPLE, std::string msg = "") : value(v), customMsg(msg) { }
    bool operator==(Fruit a) const { return value == a.value; }
    bool operator!=(Fruit a) const { return value != a.value; }

    std::string str() { return !customMsg.empty() ? customMsg : defaultMsg[value]; };
private:
    Value value;
    std::string customMsg;
    static std::map<Value, std::string> defaultMsg;
};

std::map<Fruit::Value, std::string> Fruit::defaultMsg;

int main(int argc, char** argv) {
    Fruit::setupDefaultMsg();

    Fruit apple(Fruit::APPLE), banana(Fruit::BANANA);

    cout << (apple == banana) << endl; // 0
    cout << apple.str() << endl;       // It's red.
    cout << banana.str() << endl;      // It's yellow.

    return 0;
}
