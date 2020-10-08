#include <iostream>
#include <unistd.h>

//WINDOWS
//https://stackoverflow.com/questions/33916810/delete-files-with-c-on-windows

//LINUX
//https://stackoverflow.com/questions/678325/remove-file-in-c-under-unix
//https://pubs.opengroup.org/onlinepubs/007908775/xsh/unlink.html

int main(){
    std::string fname = "tmp.txt";

#ifdef WINDOWS
    BOOL res = DeleteFile(fname.c_str());
    std::cout << (res ? "success" : "fail") << std::endl;
#else
    int success = unlink(fname.c_str());
    std::cout << (success == 0 ? "success" : "fail") << std::endl;
#endif
    
    return 0;
}
