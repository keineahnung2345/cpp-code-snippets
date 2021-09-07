#include <string>
#include <iostream>
//#include <Windows.h>

//for CA2CT
#include <atlbase.h>
#include <atlconv.h>

//https://stackoverflow.com/questions/1200188/how-to-convert-stdstring-to-lpcstr

using namespace std;

//https://stackoverflow.com/questions/8032080/how-to-convert-char-to-wchar-t
wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

int main(int argc, char** argv) {
    std::string s("hello");
    //cout cannot be used with wcout!
    //std::cout << s << std::endl;

    LPCTSTR lpc;
    LPTSTR lp;

    //cannot convert like this
    //lpc = (LPCTSTR)(s.c_str());
    //lp = (TCHAR*)(s.c_str());

    //should convert like this
    lpc = GetWC(s.c_str());
    lp = GetWC(s.c_str());

    std::cout << "=====mbstowcs=====" << std::endl;
    wprintf(L"wprintf lp: %s\n", lp);
    wprintf(L"wprintf lpc: %s\n", lpc);

    std::wcout << "wcout lp: " << lp << std::endl;
    std::wcout << "wcout lpc: " << lpc << std::endl;

    lpc = CA2CT(s.c_str());
    lp = CA2CT(s.c_str());

    //https://stackoverflow.com/questions/3020725/char-array-to-lpctstr
    std::cout << "=====CA2CT=====" << std::endl;
    wprintf(L"wprintf lp: %s\n", lp);
    wprintf(L"wprintf lpc: %s\n", lpc);

    std::wcout << "wcout lp: " << lp << std::endl;
    std::wcout << "wcout lpc: " << lpc << std::endl;

    std::cout << "=====wcout L\"xxx\"=====" << std::endl;
    std::wcout << L"hello" << std::endl;

    return 0;
}

/**
wprintf lp: hello
wprintf lpc: hello
wcout lp: hello
wcout lpc: hello
hello
**/
