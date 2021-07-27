#include <vector>
#include <string>
#include <iostream>
#include <variant>

//https://en.cppreference.com/w/cpp/utility/variant
//https://en.cppreference.com/w/cpp/utility/variant/holds_alternative
//https://en.cppreference.com/w/cpp/utility/variant/index

using namespace std;

using MyVariant = std::variant<string, double, vector<float>>;

int main(int argc, char** argv) {
    MyVariant var1 = "hello", var2 = 1.23456789, var3 = vector<float>{ 1.2f, 3.4f };
    vector<MyVariant> vars = { var1, var2, var3 };

    for (const MyVariant& var : vars) {
        if (std::holds_alternative<string>(var)) {
            cout << std::get<string>(var) << endl;
        }
        else if (std::holds_alternative<double>(var)) {
            cout << std::get<double>(var) << endl;
        }
        else if (std::holds_alternative<vector<float>>(var)) {
            vector<float> vf = std::get<vector<float>>(var);
            for (const float& f : vf) {
                cout << f << " ";
            }
            cout << endl;
        }
    }

    /**
    * hello
    * 1.23457
    * 1.2 3.4
    **/

    return 0;
}
