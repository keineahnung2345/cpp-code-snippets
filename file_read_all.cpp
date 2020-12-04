#include <fstream>
#include <string>

//https://stackoverflow.com/questions/18398167/how-to-copy-a-txt-file-to-a-char-array-in-c

int main(){
    std::ifstream in("xxx.txt");
    std::string contents((std::istreambuf_iterator<char>(in)), 
        std::istreambuf_iterator<char>());
    return 0;
}
