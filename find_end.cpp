#include <iostream>
#include <vector>
#include <algorithm> //find_end

int main()
{
    std::vector<int> v = {1, 6, 2, 3, 4, 5, 6, 2};
    std::vector<int> tofind = {6};

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int>::iterator it = std::find_end(v.begin(), v.end(), tofind.begin(), tofind.end());
    //if 6 is found
    if(it != v.end()){
        std::cout << "last 6 is the " << it - v.begin() << "th(index start from 0) value in v, " << v.end() - it << "th(index start from 1) value in reverse order." << std::endl;
    }
    return 0;
}

/*
1 6 2 3 4 5 6 2
last 6 is the 6th(index start from 0) value in v, 2th(index start from 1) value in reverse order.
*/
