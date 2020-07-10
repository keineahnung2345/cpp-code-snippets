#include <iostream>
#include <iomanip>
#include <limits> //numeric_limits

using namespace std;

enum class TYPE{
    INT, FLOAT, DOUBLE
};

//https://stackoverflow.com/questions/92396/why-cant-variables-be-declared-in-a-switch-statement
//https://stackoverflow.com/questions/554063/how-do-i-print-a-double-value-with-full-precision-using-cout

/*
by adding "{}" after "case xxx:", 
we can define variables in the case block
*/

int main() {
    double d = 3.14159265358979;
    TYPE type = TYPE::FLOAT;
    switch(type){
        case TYPE::INT:{
            int val = d;
            cout << "convert to int: " << val << endl;
            break;
        }
        case TYPE::FLOAT:{
            float val = d;
            cout << "convert to double: " << std::setprecision(std::numeric_limits<float>::max_digits10) << val << endl;
            break;
        }
        case TYPE::DOUBLE:{
            double val = d;
            cout << "convert to double: " << std::setprecision(std::numeric_limits<double>::max_digits10) << val << endl;
            break;
        }
    }
    return 0;
}
