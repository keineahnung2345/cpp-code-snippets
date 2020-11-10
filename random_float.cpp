#include <iostream>
#include <random>

using namespace std;

//https://stackoverflow.com/questions/686353/random-float-number-generation

float rand_float(int hi = 0, int lo = 0){
    if(hi == 0){
        //random number in [0,1)
        return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }else if(lo == 0){
        //random number in [0,hi)
        return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/hi));
    }else{
        //random number in [lo, hi)
        return lo + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(hi-lo)));
    }
}

int main()
{
    cout << "random number in [0,1)" << endl;
    for(int i = 0; i < 10; ++i){
        cout << rand_float() << " ";
    }
    cout << endl;
    
    int hi = 20;
    cout << "random number in [0," << hi << ")" << endl;
    for(int i = 0; i < 10; ++i){
        cout << rand_float(hi) << " ";
    }
    cout << endl;
    
    int lo = 10;
    cout << "random number in [" << lo << "," << hi << ")" << endl;
    for(int i = 0; i < 10; ++i){
        cout << rand_float(hi, lo) << " ";
    }
    cout << endl;

    return 0;
}

/*
random number in [0,1)
0.840188 0.394383 0.783099 0.79844 0.911647 0.197551 0.335223 0.76823 0.277775 0.55397 
random number in [0,20)
9.54794 12.5774 7.29569 10.268 19.0446 18.3239 12.7142 14.3459 2.83205 12.1394 
random number in [10,20)
10.163 12.4289 11.3723 18.0418 11.5668 14.0094 11.2979 11.0881 19.9892 12.1826 
*/
