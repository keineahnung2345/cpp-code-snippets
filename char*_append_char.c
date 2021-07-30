#include <stdio.h>
#include <string.h>

//https://stackoverflow.com/questions/19891962/c-how-to-append-a-char-to-char

int main(void) {
    char* src = "hell\0";
    char* tgt = (char*)malloc(sizeof(char) *strlen(src)+2);
    strcpy(tgt, src);
    tgt[strlen(src)] = 'o';
    tgt[strlen(src)+1] = '\0';
    printf("source: %s, len: %d\n", src, strlen(src));
    printf("target: %s, len: %d\n", tgt, strlen(tgt));
    return 0;
}
