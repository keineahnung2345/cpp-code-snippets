#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c

int main(){
    struct stat st = {0};

    if (stat("newdir", &st) == -1) { //checking if the directory exists
        mkdir("newdir", 0700);
    }
}
