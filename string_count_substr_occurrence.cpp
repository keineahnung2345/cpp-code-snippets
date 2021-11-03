#include <iostream>
#include <string>

int count_substring(const std::string& str, const std::string& sub) {
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
        offset = str.find(sub, offset + sub.length())) {
        ++count;
    }
    return count;
}

int main() {
    std::string str = "Class::function::lambda::operator()";
    size_t cnt = count_substring(str, "::");
    std::cout << "There are " << cnt << " :: in " << str << std::endl;
    // There are 3 :: in Class::function::lambda::operator()
    return 0;
}
