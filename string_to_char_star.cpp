#include <string.h>
#include <string>

//this can replace the above 2
//#include <bits/stdc++.h> 

//https://www.geeksforgeeks.org/convert-string-char-array-cpp/

int main()
{
    std::string s = "geeksforgeeks";

    int n = s.length();

    char char_array[n + 1];

    // copying the contents of the 
    // string to char array 
    strcpy(char_array, s.c_str());

    for (int i = 0; i < n; i++){
        std::cout << char_array[i];
    }
    std::cout << std::endl;

    return 0;
}
