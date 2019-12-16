#include <iostream>
#include <vector>
#include <algorithm> //find

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 5, 2, 5};
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 5);
    while(it != v.end()){
        std::cout << "index: " << it - v.begin() << ", value: " << *it << std::endl;
        it = std::find(it+1, v.end(), 5);
    }
    return 0;
}
