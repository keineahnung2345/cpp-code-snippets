#include <iostream>
#include <string>
#include <vector>

//https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda

int main(){
    std::vector<std::string> myvec;
    myvec = {"apple", "lemon", "orange", "banana", "onion", "melon", "durian"};
    //first sort by length(the longer the former), then by lexicographical order
    std::sort(myvec.begin(), myvec.end(),
        [](const std::string& a, const std::string& b) -> bool{return a.size() == b.size() ? a < b : a.size() > b.size();});
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

//banana durian orange apple lemon melon onion
