#include <iostream>
#include <vector>
#include <set>

using namespace std;

//revised from
//https://stackoverflow.com/questions/34052948/printing-any-stl-container
template<template<typename, typename...> class TT, typename... Args>
void output_container(TT<Args...> const &cont){
    for(auto elem : cont) cout << elem << " ";
    cout << endl;
}

int main() {
    char arrc[]= {'a', 'b', 'd', 'e', 'f'};
    string arrs[] = {"abc", "def", "ghi"};
    
    vector<int> v {1,2,3,4,5,6};
    set<char> msc(arrc, arrc+3);
    set<string> mss(arrs, arrs+3);
    string s = "abcdefg";
    
    output_container(v);
    output_container(msc);
    output_container(mss);
    output_container(s);
}
