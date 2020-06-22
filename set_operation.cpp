#include <iostream>
#include <set>
#include <vector>
#include <iterator> //ostream_iterator
#include <algorithm> //set_symmetric_difference

//http://www.cplusplus.com/reference/algorithm/set_union/

int main()
{
    std::set<char> s1, s2;
    std::vector<char> v(10); //need to reserve places
    std::vector<char>::iterator v_it;
    
    s1.insert('d');
    s1.insert('a');
    s1.insert('c');
    s1.insert('b');

    std::cout << "s1: " << std::endl;
    std::copy(s1.begin(), s1.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    s2.insert('c');
    s2.insert('e');
    s2.insert('b');

    std::cout << "s2: " << std::endl;
    std::copy(s2.begin(), s2.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    std::cout << "intersection:" << std::endl;
    v_it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    //resize it to retain only the meaningful values
    v.resize(v_it-v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    std::cout << "union:" << std::endl;
    v.resize(10);
    v_it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    //resize it to retain only the meaningful values
    v.resize(v_it-v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    std::cout << "difference:" << std::endl;
    v.resize(10);
    v_it = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    v.resize(v_it-v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    std::cout << "symmetric difference:" << std::endl;
    v.resize(10);
    v_it = set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    v.resize(v_it-v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    
    return 0;
}

/*
s1: 
a b c d 
s2: 
b c e 
intersection:
b c 
union:
a b c d e 
difference:
a d
symmetric difference:
a d e 
*/
