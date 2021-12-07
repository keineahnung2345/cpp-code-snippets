#include <iostream>
#include <vector>

class Person {
public:
    Person(int a) : age(a) {}

private:
    int age;
};

// https://stackoverflow.com/questions/4754763/object-array-initialization-without-default-constructor

int main() {
    // method 1
    std::vector<Person> people(10, Person(0));

    // method 2
    std::vector<Person> people2;
    people2.reserve(10);
    for(size_t i = 0; i < 10; ++i) people2.emplace_back(i);

    return 0;
}
