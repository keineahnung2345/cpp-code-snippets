#include <stdio.h>

//https://stackoverflow.com/questions/3381080/reading-all-content-from-a-text-file-c

int main(int argc, char** argv) {
    FILE* fp = fopen("abc.txt", "r");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* fcontent = (char*)malloc(size);
    fread(fcontent, 1, size, fp);
    fclose(fp);

    printf("%s\n", fcontent);

    return 0;
}
