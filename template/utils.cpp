#ifndef CORRECT
#include <sstream> //std::ostringstream

template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& separator)
{
    std::ostringstream result;
    result.precision(2); //for floating point
    if (begin != end)
        result << *begin++;
    while (begin != end)
        //std::fixed : for floating point
        result << std::fixed << separator << *begin++;
    return result.str();
}
#endif
