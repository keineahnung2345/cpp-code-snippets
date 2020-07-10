#include <vector>
#include <set>
#include <iostream>

//https://stackoverflow.com/questions/12850927/adding-elements-of-a-vector-to-an-unordered-set

int main()
{
    std::vector<int> v = {1, 3, 3, 5, 7, 7, 7};

    //initialize set with vector
    std::set<int> myset(v.begin(), v.end());
    for(std::set<int>::iterator it = myset.begin(); it!=myset.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //initialize set with string
    std::string mystr = "hello";
    std::set<char> mysetc(mystr.begin(), mystr.end());
    for(std::set<char>::iterator it = mysetc.begin(); it!=mysetc.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    //append set with vector
    v = {8, 9, 10, 8};
    std::copy(v.begin(),v.end(),std::inserter(myset, myset.end()));
    for(std::set<int>::iterator it = myset.begin(); it!=myset.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
1 3 5 7 
e h l o 
1 3 5 7 8 9 10 
*/
