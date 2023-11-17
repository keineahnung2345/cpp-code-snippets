#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
    std::stringstream ss;
    auto              oldFlags     = ss.flags();
    auto              oldPrecision = ss.precision();

    float f1 = 1.2345f, f2 = 10.0f;
    ss << std::fixed << std::setprecision(1) << f1 << " " << f2;
    std::cout << ss.str() << std::endl; // 1.2 10.0
    ss.str("");

    ss.flags(oldFlags);
    ss.precision(oldPrecision);
    ss << f1 << " " << f2;
    std::cout << ss.str() << std::endl; // 1.2345 10

    return 0;
}
