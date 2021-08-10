#include <Windows.h>
#include <string>
#include <iostream>

//https://github.com/keineahnung2345/cpp-code-snippets/blob/master/windows/string_to_lptstr_lpctstr.cpp
wchar_t* charToWchart(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

//https://stackoverflow.com/questions/15435994/how-do-i-open-an-exe-from-another-c-exe
//https://stackoverflow.com/questions/14290291/run-external-exe-and-receive-return-value-from-it
//https://stackoverflow.com/questions/11725958/getexitcodeprocess-return-1-when-process-is-not-yet-finished
//https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess
//https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw
//https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess
int startup(LPCTSTR lpApplicationName, LPTSTR lpCommandLine)
{
    // additional information
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    BOOL res = CreateProcess(lpApplicationName,   // the path
        lpCommandLine,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );

    int retVal;
    if (!res) {
        std::cout << "not res" << std::endl;
        retVal = -1;
    }
    else {
        // wait for completion
        DWORD exitCode = 0;
        res = WaitForSingleObject(
            pi.hProcess,
            INFINITE      // time-out interval in milliseconds  
        );
        if (GetExitCodeProcess(pi.hProcess, &exitCode) == FALSE) {
            //GetExitCodeProcess fails
            retVal = -2;
        }
        else if (exitCode == STILL_ACTIVE) {
            //If the process has not terminated and the function succeeds, 
            //the status returned is STILL_ACTIVE
            retVal = -3;
        }
        else {
            retVal = (int)exitCode;
        }
    }

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return retVal;
}

int main(int argc, char** argv) {
    std::string program = "xxx.exe";
    std::string sArguments = "the executable's command line argument, note that string argument should be surrounded by \"";
    std::string programAndArguments = program + " " + sArguments;
    int retVal = startup(NULL, charToWchart(programAndArguments.c_str()));
    std::cout << "retVal: " << retVal << std::endl;
    return 0;
}
