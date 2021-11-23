/**Error	C4996	'mbstowcs': This function or variable may be unsafe.
 * Consider using mbstowcs_s instead. To disable deprecation, use
 * _CRT_SECURE_NO_WARNINGS. See online help for details.*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
//#include <Windows.h>

// for CA2CT
#include <atlbase.h>
#include <atlconv.h>

// https://stackoverflow.com/questions/1200188/how-to-convert-stdstring-to-lpcstr

using namespace std;

// https://stackoverflow.com/questions/8032080/how-to-convert-char-to-wchar-t
wchar_t* GetWC(const char* c) {
    const size_t cSize = strlen(c) + 1;
    wchar_t*     wc    = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

// https://stackoverflow.com/questions/27220/how-to-convert-stdstring-to-lpcwstr-in-c-unicode
std::wstring s2ws(const std::string& s) {
    int len;
    int slength  = (int)s.length() + 1;
    len          = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

int main(int argc, char** argv) {
    std::string s("hello");
    // cout cannot be used with wcout!
    // std::cout << s << std::endl;

    wchar_t* wc = GetWC(s.c_str());
    std::cout << "=====wchar_t*=====" << std::endl;
    // https://stackoverflow.com/questions/2493785/how-i-can-print-the-wchar-t-values-to-console
    std::wcout << wc << std::endl;

    LPCTSTR lpc;
    LPTSTR  lp;

    // cannot convert like this
    // lpc = (LPCTSTR)(s.c_str());
    // lp = (TCHAR*)(s.c_str());

    std::cout << "=====mbstowcs=====" << std::endl;
    // should convert like this
    lpc = GetWC(s.c_str());
    lp  = GetWC(s.c_str());

    wprintf(L"wprintf lp: %s\n", lp);
    wprintf(L"wprintf lpc: %s\n", lpc);

    std::wcout << "wcout lp: " << lp << std::endl;
    std::wcout << "wcout lpc: " << lpc << std::endl;

    // https://stackoverflow.com/questions/3020725/char-array-to-lpctstr
    std::cout << "=====CA2CT=====" << std::endl;
    lpc = CA2CT(s.c_str());
    lp  = CA2CT(s.c_str());

    wprintf(L"wprintf lp: %s\n", lp);
    wprintf(L"wprintf lpc: %s\n", lpc);

    std::wcout << "wcout lp: " << lp << std::endl;
    std::wcout << "wcout lpc: " << lpc << std::endl;

    // https://stackoverflow.com/questions/27220/how-to-convert-stdstring-to-lpcwstr-in-c-unicode
    std::cout << "=====MultiByteToWideChar=====" << std::endl;
    std::wstring stemp = s2ws(s);
    LPCWSTR      lpcw  = stemp.c_str();
    // https://stackoverflow.com/questions/9825951/how-to-convert-lpcwstr-to-lpwstr/9826001
    LPWSTR       lpw   = &stemp[0];

    wprintf(L"wprintf lpw: %s\n", lpw);
    wprintf(L"wprintf lpcw: %s\n", lpcw);

    std::wcout << "wcout lpw: " << lpw << std::endl;
    std::wcout << "wcout lpcw: " << lpcw << std::endl;

    std::cout << "=====wcout L\"xxx\"=====" << std::endl;
    std::wcout << L"hello" << std::endl;

    return 0;
}

/**
=====wchar_t*=====
hello
=====mbstowcs=====
wprintf lp: hello
wprintf lpc: hello
wcout lp: hello
wcout lpc: hello
=====CA2CT=====
wprintf lp: hello
wprintf lpc: hello
wcout lp: hello
wcout lpc: hello
=====MultiByteToWideChar=====
wprintf lpw: hello
wprintf lpcw: hello
wcout lpw: hello
wcout lpcw: hello
=====wcout L"xxx"=====
hello
**/
