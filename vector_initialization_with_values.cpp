#include <iostream>
#include <vector>
#include <iterator> //ostream_iterator

//https://stackoverflow.com/questions/4268886/initialize-a-std::vector-array-of-strings
//https://stackoverflow.com/questions/13110130/initialize-a-vector-to-zeros-c-c11

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b;
    b = {5,6,7};
    std::vector<int> c(10, 1);
    std::copy(c.begin(), c.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //1 1 1 1 1 1 1 1 1 1 
    
    std::vector<std::string> vs({ "xyzzy", "plugh", "abracadabra" });
    std::copy(vs.begin(), vs.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    //xyzzy plugh abracadabra 
    
    return 0;
}
