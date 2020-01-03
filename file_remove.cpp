#include <iostream>
#include <unistd.h>

//https://stackoverflow.com/questions/678325/remove-file-in-c-under-unix
//https://pubs.opengroup.org/onlinepubs/007908775/xsh/unlink.html

int main(){
    std::string fname = "tmp.txt";

    int success = unlink(fname.c_str());
    std::cout << (success == 0 ? "success" : "fail") << std::endl;
    return 0;
}
