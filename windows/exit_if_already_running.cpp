#include <Windows.h>
#include <string>
#include <iostream>

bool exitIfAlreadyRunning(const std::string& title);

int main() {
    exitIfAlreadyRunning("My App");
    for(size_t i = 0; i < 50; ++i) {
        std::cout << i << std::endl;
        Sleep(1000);
    }
    return 0;
}

bool exitIfAlreadyRunning(const std::string& title) {
    // https://stackoverflow.com/questions/4191465/how-to-run-only-one-instance-of-application
    bool        ret    = true;
    const char* cTitle = title.c_str();
    wchar_t*    wTitle = new wchar_t[strlen(cTitle) + 1];
    mbstowcs(wTitle, cTitle, strlen(cTitle) + 1);

    SetConsoleTitle(wTitle);
    HANDLE m_singleInstanceMutex = CreateMutex(NULL, TRUE, L"Server Mutex");
    if(m_singleInstanceMutex == NULL ||           // failure
       GetLastError() == ERROR_ALREADY_EXISTS) {  // mutex already existed
        HWND existingApp = FindWindow(0, wTitle);
        delete[] wTitle;
        if(existingApp) SetForegroundWindow(existingApp);
        exit(EXIT_FAILURE);  // exit the app
    }

    delete[] wTitle;
    return ret;
}
