#include <map>
#include <iostream>
#include <string>

template <typename T>
void print_map(T m){
    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

//http://www.cplusplus.com/reference/map/map/operator[]/
//https://stackoverflow.com/questions/2667355/mapint-int-default-values

int main(){
    std::map<int, int> m_i;
    std::map<int, std::string> m_s;

    m_i[0]++;
    m_s[0] += 'a';

    print_map(m_i);
    print_map(m_s);
    return 0;
}

/*
0 1
0 a
*/
