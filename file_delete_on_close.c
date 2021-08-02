//#include <fileapi.h>
//#include <WinBase.h> //FILE_FLAG_DELETE_ON_CLOSE 
#include <windows.h> //https://stackoverflow.com/questions/4845198/fatal-error-no-target-architecture-in-visual-studio
#include <io.h> //_open_osfhandle
#include <fcntl.h> //_O_RDONLY,  _O_WRONLY
#include <stdio.h>

//https://stackoverflow.com/questions/12249610/c-create-file-in-memory
//https://docs.microsoft.com/zh-tw/windows/win32/fileio/creating-and-using-a-temporary-file
FILE* createTempFile() {
    TCHAR szTempFileName[MAX_PATH] = { 0 };
    TCHAR lpTempPathBuffer[MAX_PATH] = { 0 };

    DWORD dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
        lpTempPathBuffer);
    if (dwRetVal > MAX_PATH || (dwRetVal == 0)) {
        printf("GetTempPath failed\n");
        return NULL;
    }
    //wprintf(L"temp path: %s\n", lpTempPathBuffer);
    //temp path: C:\Users\xxx\AppData\Local\Temp\

    UINT uRetVal = GetTempFileName(lpTempPathBuffer, // directory for tmp files
        TEXT("DEMO"),     // temp file name prefix 
        0,                // create unique name 
        szTempFileName);  // buffer for name 
    if (uRetVal == 0) {
        printf("GetTempFileName failed\n");
        return NULL;
    }
    //wprintf(L"temp name: %s\n", szTempFileName);
    //temp name: C:\Users\xxx\AppData\Local\Temp\DEM6C25.tmp

    HANDLE hTempFile = CreateFile((LPTSTR)szTempFileName, // file name 
        GENERIC_READ | GENERIC_WRITE,        // open for write 
        0,                    // do not share 
        NULL,                 // default security 
        CREATE_ALWAYS,        // overwrite existing
        FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE,// normal file 
        NULL);                // no template 

    //https://stackoverflow.com/questions/5193579/how-make-file-from-handle-in-winapi
    int nHandle = _open_osfhandle((long)hTempFile, _O_RDONLY | _O_WRONLY);
    if (nHandle == -1) {
        ::CloseHandle(hTempFile);   //case 1
        return nullptr;
    }
    FILE* fp = _fdopen(nHandle, "w+");
    if (!fp) {
        ::CloseHandle(hTempFile);  //case 2
    }
    return fp;
}

int main() {
    FILE* fp = createTempFile();
    
    char buffer[] = { 'H','e','l', 'l','o' };
    if (fp == NULL) {
        printf("open failure");
        return 1;
    }
    fwrite(buffer, 1, sizeof(buffer), fp);
    fflush(fp);
    fclose(fp);
    return 0;
}
