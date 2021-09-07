#include <string>
#include <iostream>
#include <chrono>

#include <Windows.h>
#include <atlbase.h> //CA2CT
#include <atlconv.h> //CA2CT

//https://stackoverflow.com/questions/20370920/convert-current-time-from-windows-to-unix-timestamp-in-c-or-c
unsigned long long FileTimeToUnixTime(FILETIME ft) {
    //Copy the low and high parts of FILETIME into a LARGE_INTEGER
    //This is so we can access the full 64-bits as an Int64 without causing an alignment fault
    LARGE_INTEGER li;
    li.LowPart = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;

    //Convert ticks since 1/1/1970 into seconds
    const __int64 UNIX_TIME_START = 0x019DB1DED53E8000; //January 1, 1970 (start of Unix epoch) in "ticks"
    const __int64 TICKS_PER_SECOND = 10000000; //a tick is 100ns
    return static_cast<unsigned long long>((li.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND);
}

//https://docs.microsoft.com/en-us/windows/win32/sysinfo/retrieving-the-last-write-time
unsigned long long get_file_creation_time(const std::string& fname) {
    FILETIME ftCreate, ftAccess, ftWrite;
    OFSTRUCT buffer;
    HANDLE hfile = CreateFile(CA2CT(fname.c_str()),               // file to open
        GENERIC_READ,          // open for reading
        FILE_SHARE_READ,       // share for reading
        NULL,                  // default security
        OPEN_EXISTING,         // existing file only
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
        NULL);                 // no attr. template

    // Retrieve the file times for the file.
    if (!GetFileTime(hfile, &ftCreate, &ftAccess, &ftWrite))
        return FALSE;

    //// Convert the last-write time to local time.
    //SYSTEMTIME stUTC, stLocal;
    //FileTimeToSystemTime(&ftCreate, &stUTC);
    //SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    //SystemTimeToFileTime(&stLocal, &ftCreate);

    unsigned long long ftCreateUnix = FileTimeToUnixTime(ftCreate);

    CloseHandle(hfile);

    return ftCreateUnix;
}

int main(int argc, char** argv) {
    //https://www.epochconverter.com/
    double now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    //https://stackoverflow.com/questions/5212018/how-to-make-c-cout-not-use-scientific-notation
    // add std::fixed to not using scientific notation
    std::cout << "now: " << std::fixed << now << std::endl;

    std::string fname = "c.txt";
    unsigned long long int tunix = get_file_creation_time(fname);
    std::cout << fname << " created at " << tunix << std::endl;
    
    return 0;
}

//now: 1630998850.000000
//c.txt created at 1630996549
