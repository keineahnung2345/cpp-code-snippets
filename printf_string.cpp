#include <stdio.h>
#include <string>

//https://stackoverflow.com/questions/10865957/printf-with-stdstring

int main(){
    std::string s = "hello";
    
    //Method 1(wrong)
    printf("%s\n", s);
    //0?O??
    //warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘std::__cxx11::string* {aka std::__cxx11::basic_string<char>*}’ [-Wformat=]

    //Method 2(correct)
    printf("%s\n", s.c_str());
    //hello
    return 0;
}
