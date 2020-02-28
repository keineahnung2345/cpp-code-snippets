#include <vector>
#include <set>

int main()
{
    std::vector<int> v = {1, 3, 3, 5, 7, 7, 7};

    std::set<int> myset(v.begin(), v.end());

    for(std::set<int>::iterator it = myset.begin(); it!=myset.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::string mystr = "hello";
    std::set<char> mysetc(mystr.begin(), mystr.end());
    for(std::set<char>::iterator it = mysetc.begin(); it!=mysetc.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
1 3 5 7
e h l o 
*/
