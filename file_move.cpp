#include <iostream>

#ifdef WINDOWS
#include <WinBase.h>
//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-movefile
#else
#include <unistd.h>
#endif

int main(){
    std::string fname = "tmp.txt";
    std::string newfname = "yyy.txt";

#ifdef WINDOWS
    BOOL res = MoveFile(fname.c_str(), newfname.c_str());
    std::cout << (res ? "success" : "fail") << std::endl;
#else
#endif
    
    return 0;
}
