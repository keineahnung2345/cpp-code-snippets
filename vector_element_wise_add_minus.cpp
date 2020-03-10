#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/3376124/how-to-add-element-by-element-of-two-stl-vectors

int main(){
    std::vector<int> myvec = {1,2,3,4,5};
    std::vector<int> ones(myvec.size(), 1);
    std::vector<int> result(myvec.size());

    std::transform(myvec.begin(), myvec.end(), ones.begin(),
               result.begin(), std::plus<int>());

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::transform(myvec.begin(), myvec.end(), ones.begin(),
               result.begin(), std::minus<int>());

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

/*
2 3 4 5 6
0 1 2 3 4 
*/
