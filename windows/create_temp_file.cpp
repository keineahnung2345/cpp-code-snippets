#include <windows.h>
#include <io.h> //_open_osfhandle
#include <fcntl.h> //_O_RDONLY,  _O_WRONLY

/**
 * @brief This is useful when used with a class C having a function F that
 * writes to a file but not having a function converting its content into a
 * string. By using this, one can first call C::F writing C's content into a
 * file and then read from that file into a string
 * @return
 */
FILE* createTempFile() {
    TCHAR szTempFileName[MAX_PATH]   = { 0 };
    TCHAR lpTempPathBuffer[MAX_PATH] = { 0 };
    DWORD dwRetVal = GetTempPath(MAX_PATH,  // length of the buffer
                                 lpTempPathBuffer);
    if(dwRetVal > MAX_PATH || (dwRetVal == 0)) {
        printf("GetTempPath failed\n");
        return NULL;
    }
    // wprintf(L"temp path: %s\n", lpTempPathBuffer);
    UINT uRetVal = GetTempFileName(lpTempPathBuffer,  // directory for tmp files
                                   TEXT("DEMO"),      // temp file name prefix
                                   0,                 // create unique name
                                   szTempFileName);   // buffer for name
    if(uRetVal == 0) {
        printf("GetTempFileName failed\n");
        return NULL;
    }
    // wprintf(L"temp name: %s\n", szTempFileName);
    HANDLE hTempFile = CreateFile(
        (LPTSTR)szTempFileName,        // file name
        GENERIC_READ | GENERIC_WRITE,  // open for write
        0,                             // do not share
        NULL,                          // default security
        CREATE_ALWAYS,                 // overwrite existing
        FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE,  // normal file
        NULL);                                                 // no template
    // https://stackoverflow.com/questions/5193579/how-make-file-from-handle-in-winapi
    int nHandle = _open_osfhandle((long)hTempFile, _O_RDONLY | _O_WRONLY);
    if(nHandle == -1) {
        ::CloseHandle(hTempFile);  // case 1
        return nullptr;
    }
    FILE* fp = _fdopen(nHandle, "w+");
    if(!fp) {
        ::CloseHandle(hTempFile);  // case 2
    }
    return fp;
};

int main() {
    FILE* fp = createTempFile();
    int num = 1;
    fprintf(fp, "This is %d example sentence.", num);
    fflush(fp);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* fcontent = static_cast<char*>(malloc(size));
    fread(fcontent, 1, size, fp);
    fclose(fp);

    std::string sfcontent(fcontent, size);
    std::cout << sfcontent << std::endl; // This is %d example sentence.
    return 0;
}
