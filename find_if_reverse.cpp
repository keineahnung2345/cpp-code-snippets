#include <algorithm>
#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/39165432/find-last-element-in-stdvector-which-satisfies-a-condition

int main(){
    std::vector<int> v{1,2,42,42,63};
    auto result = std::find_if(v.rbegin(), v.rend(),
        [](int i) { return i == 42; });

    std::cout << std::distance( result, v.rend()-1) << '\n';
}

//3
