#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// https://stackoverflow.com/questions/47350924/iterating-through-a-vector-of-tuples-c17-style-dont-work

int main() {
    std::vector<std::tuple<std::string, int, float>> students;
    students.emplace_back("Jack", 10, 30.3);
    students.emplace_back("Marry", 9, 60.1);
    students.emplace_back("Kevin", 11, 77.2);
    for(auto const& [name, age, score] : students) {
        std::cout << name << ", " << age << ", " << score << std::endl;
    }
    return 0;
}

/*
Jack, 10, 30.3
Marry, 9, 60.1
Kevin, 11, 77.2
*/
