#include <stdio.h>
//https://stackoverflow.com/questions/16518210/sqrt-is-not-a-member-of-std
//use cmath instead of math.h in C++
//#include <math.h>
#include <cmath> //std::fabs
#include <limits> //std::numeric_limits<float>::epsilon()

int main(){
    float a = 0.000001, b = 0.000002;
    if(std::fabs(a-b) > std::numeric_limits<float>::epsilon() * 10){
        printf("a and b's difference is larger than epsilon * 10!\n");
    }else{
        printf("a and b's difference is not larger than epsilon * 10!\n");
    }
    return 0;
}
