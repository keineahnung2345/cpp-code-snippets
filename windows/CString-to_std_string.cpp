#include <iostream>
#include <string>
#include <Windows.h>

// https://stackoverflow.com/questions/258050/how-do-you-convert-cstring-and-stdstring-stdwstring-to-each-other

int main(int argc, char** argv) {
    CString     csMsg("Hello");
    CT2CA       caMsg(csMsg);
    std::string sMsg(caMsg);
    return 0;
}
