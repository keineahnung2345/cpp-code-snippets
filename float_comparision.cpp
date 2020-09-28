#include <stdio.h>
//https://stackoverflow.com/questions/16518210/sqrt-is-not-a-member-of-std
//use cmath instead of math.h in C++
//#include <math.h>
#include <cmath> //std::fabs
#include <limits> //std::numeric_limits<float>::epsilon()
#include <algorithm> //std::max

//https://stackoverflow.com/questions/17333/what-is-the-most-effective-way-for-float-and-double-comparison

int main(){
    float a = 2.345678f, b = 2.345677f;
    if(std::fabs(a-b) > std::numeric_limits<float>::epsilon() * std::max(std::fabs(a), std::fabs(b))){
        printf("a and b are not equal\n");
    }else{
        printf("a and b are close enough\n");
    }
    return 0;
}

//a and b are not equal
