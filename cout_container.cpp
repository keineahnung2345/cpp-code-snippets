#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

//revised from
//https://stackoverflow.com/questions/34052948/printing-any-stl-container

//output ordinary element
template<typename T>
void output_element(T const &elem) { 
    cout << "'" << elem << "'" << " ";
}

//output pair
template<typename T1, typename T2>
void output_element(pair<T1, T2> const &elem) { 
    cout << "{" << elem.first << " " << elem.second << "} ";
}

//output container, can work with vector, array, set, map, ...
template<template<typename, typename...> class TT, typename... Args>
void output_container(TT<Args...> const &cont){
    for(auto elem : cont) output_element(elem);
    cout << endl;
}

int main() {
    char arrc[]= {'a', 'b', 'd', 'e', 'f'};
    string arrs[] = {"abc", "def", "ghi"};
    map<char, int> mapci;
    
    vector<int> v {1,2,3,4,5,6};
    set<char> msc(arrc, arrc+3);
    set<string> mss(arrs, arrs+3);
    string s = "abcdefg";
    mapci['a'] = 3;
    mapci['b'] = 0;
    mapci['c'] = 9;
    
    output_container(v);
    output_container(msc);
    output_container(mss);
    output_container(s);
    output_container(mapci);
}
