#include <iostream>
  
#ifdef _MSC_VER
#define FN_NAME __FUNCTION__
#else
#define FN_NAME __func__
#endif

#define NULLPTR

#define CHECK_NULL_RET_VAL(ptr, val)                                                           \
    if ((ptr) == nullptr)                                                                      \
    {                                                                                          \
        std::cout << "Error: input " << #ptr << " is NULL in " << FN_NAME << std::endl;        \
        return val;                                                                            \
    }

//https://stackoverflow.com/questions/14351971/what-does-x-inside-a-c-macro-mean

int main(){
#ifdef NULLPTR
    int* p = nullptr;
#else
    int i = 3;
    int* p = &i;
#endif
    CHECK_NULL_RET_VAL(p, 0)
    return 0;
}

//Error: input p is NULL in main
