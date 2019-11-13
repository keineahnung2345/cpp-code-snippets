#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

//https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c

int main(){
    struct stat st = {0};

    if (stat("newdir", &st) == -1) { //checking if the directory exists
        mkdir("newdir", 0755);
    }
    
    std::string mydir = "mydir";
    //need to convert from std::string to const char*
    if (stat(mydir.c_str(), &st) == -1) { //checking if the directory exists
        mkdir(mydir.c_str(), 0755);
    }
}
