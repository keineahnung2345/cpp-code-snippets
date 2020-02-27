#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/3376124/how-to-add-element-by-element-of-two-stl-vectors

int main(){
    std::vector<int> myvec = {1,2,3,4,5};
    std::vector<int> ones(myvec.size(), 1);

    std::transform(myvec.begin(), myvec.end(), ones.begin(),
               myvec.begin(), std::plus<int>());

    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

//2 3 4 5 6
