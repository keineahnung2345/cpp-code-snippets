#include <cstdlib> //malloc
  
int main(){
    //void* -> float* can be performed by static_cast, no need reinterpret_cast
    void* ptr;
    float* fptr;
    ptr = malloc(sizeof(float) * 100);
    fptr = static_cast<float*>(ptr);
    //fptr = reinterpret_cast<float*>(ptr);

    //const void* -> const float* can be performed by static_cast, no need reinterpret_cast
    const void* cptr;
    const float* cfptr;
    cptr = malloc(sizeof(float) * 100);
    cfptr = static_cast<const float*>(cptr);
    //cfptr = reinterpret_cast<const float*>(cptr);
    return 0;
}
