#include <stdio.h>
#include <string.h> //memcpy, strlen

//https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char

int main()
{
    char* src = "hello world";
    char dst[6];
    memcpy(dst, &src[6], strlen(&src[6]));
    dst[5] = '\0';

    printf("src: %s\n", src);
    printf("dst: %s\n", dst);

    return 0;
}
