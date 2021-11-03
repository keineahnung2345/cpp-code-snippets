#include <iostream>
#include <string>

//https://stackoverflow.com/questions/18972258/index-of-nth-occurrence-of-the-string

int find_nth_occurrence(const std::string& str, const std::string& sub, int nth) {
    size_t  pos = 0;
    int     cnt = 0;

    while (cnt != nth) {
        pos += 1;
        pos = str.find(sub, pos);
        if (pos == std::string::npos)
            return -1;
        cnt++;
    }
    return pos;
}

int main() {
    std::string str = "Class::function::lambda::operator()";
    size_t pos = find_nth_occurrence(str, "::", 2);
    std::cout << "2nd :: is at: " << pos << std::endl; //2nd :: is at: 15
    std::cout << str.substr(0, pos) << std::endl;      //Class::function
    return 0;
}
