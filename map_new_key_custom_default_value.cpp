#include <iostream>
#include <map>

// https://stackoverflow.com/questions/2333728/stdmap-default-value
// https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
// https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument

struct IntWithDefaultValue {
    int  i = -1;
         operator int() const { return i; }
    int &operator=(const int &i_in) {
        i = i_in;
        return i;
    }
};

struct StringWithDefaultValue {
    std::string  s = "defaultstring";
                 operator std::string() const { return s; }
    std::string &operator=(const std::string &s_in) {
        s = s_in;
        return s;
    }
    friend std::ostream &operator<<(std::ostream &                os,
                                    const StringWithDefaultValue &swdv) {
        os << swdv.s;
        return os;
    }
};

int main() {
    std::map<std::string, IntWithDefaultValue> intmap;
    std::cout << intmap["hello"] << std::endl;  // -1
    intmap["bye"] = 2;
    std::cout << intmap["bye"] << std::endl;  // 2

    std::map<std::string, StringWithDefaultValue> strmap;
    std::cout << strmap["a"] << std::endl;  // defaultstring
    return 0;
}
