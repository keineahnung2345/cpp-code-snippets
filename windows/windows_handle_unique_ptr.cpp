/**
 * This file defines a class WinHandle, which is a unique_ptr of windows HANDLE,
 * and demo its usage with earlier defined functions "ping" and
 * "getFileCreationTime"
 */
#include <chrono>
#include <iostream>
#include <string>

/**
* Error C4996 'inet_addr' : Use inet_pton() or InetPton() instead or
define _WINSOCK_DEPRECATED_NO_WARNINGS to disable
deprecated API warnings test C
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <atlbase.h>
#include <atlconv.h>
#include <io.h> //_open_osfhandle
#include <fcntl.h> //_O_RDONLY,  _O_WRONLY
#include <windows.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

// https://stackoverflow.com/questions/12184779/using-stdunique-ptr-for-windows-handles
class WinHandle {
    HANDLE value_;

public:
    WinHandle(std::nullptr_t = nullptr) : value_(nullptr) {}
    WinHandle(HANDLE value)
        : value_(value == INVALID_HANDLE_VALUE ? nullptr : value) {}
    explicit    operator bool() const { return value_ != nullptr; };
                operator HANDLE() const { return value_; };
    /**
    friend:
    https://www.geeksforgeeks.org/friend-class-function-cpp/
    meaning the global functions "bool operator==(WinHandle l, WinHandle r)" and
    "bool operator!=(WinHandle l, WinHandle r)" can access WinHandle's
    protected/private members
    */
    friend bool operator==(WinHandle l, WinHandle r);
    friend bool operator!=(WinHandle l, WinHandle r);
    struct Deleter {
        typedef WinHandle pointer;
        void              operator()(WinHandle handle) const {
            DWORD flags = 0;
            if(GetHandleInformation(handle, &flags)) {
                CloseHandle(handle);
            }
        };
    };
};

/**
Why putting inline function definitions in header?
https://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header
Because of the one definition rule (ODR) for inline functions, an identical
definition for the function must exist in every translation unit that uses it.
The easiest way to achieve this is by putting the definition in a header file.
*/
inline bool operator==(HANDLE l, WinHandle r) {
    return WinHandle(l) == r;
}
inline bool operator!=(HANDLE l, WinHandle r) {
    return !(l == r);
}
inline bool operator==(WinHandle l, HANDLE r) {
    return l == WinHandle(r);
}
inline bool operator!=(WinHandle l, HANDLE r) {
    return !(l == r);
}
inline bool operator==(WinHandle l, WinHandle r) {
    return l.value_ == r.value_;
}
inline bool operator!=(WinHandle l, WinHandle r) {
    return !(l == r);
}
typedef std::unique_ptr<WinHandle, WinHandle::Deleter> HandlePtr;

// https://docs.microsoft.com/zh-tw/windows/win32/api/icmpapi/nf-icmpapi-icmpsendecho?redirectedfrom=MSDN
int ping(const std::string& sipaddr) {
    // Declare and initialize variables

    HandlePtr     hIcmpFile;
    unsigned long ipaddr       = INADDR_NONE;
    DWORD         dwRetVal     = 0;
    char          SendData[32] = "Data Buffer";
    LPVOID        ReplyBuffer  = NULL;
    DWORD         ReplySize    = 0;

    // Error	C4996	'inet_addr': Use inet_pton() or InetPton() instead or
    // define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
    ipaddr = inet_addr(sipaddr.c_str());
    if(ipaddr == INADDR_NONE) {
        return 1;
    }

    hIcmpFile = HandlePtr(IcmpCreateFile());
    if(!hIcmpFile) {
        printf("\tUnable to open handle.\n");
        printf("IcmpCreatefile returned error: %ld\n", GetLastError());
        return 1;
    }

    ReplySize   = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID*)malloc(ReplySize);
    if(ReplyBuffer == NULL) {
        printf("\tUnable to allocate memory\n");
        return 1;
    }

    dwRetVal = IcmpSendEcho(hIcmpFile.get(), ipaddr, SendData, sizeof(SendData),
                            NULL, ReplyBuffer, ReplySize, 1000);
    if(dwRetVal != 0) {
        PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
        // https://stackoverflow.com/questions/32179834/how-can-i-ping-remote-computer-on-my-windows-computer-with-c
        free(ReplyBuffer);
        struct in_addr ReplyAddr;
        ReplyAddr.S_un.S_addr = pEchoReply->Address;
        printf("\tSent icmp message to %s\n", sipaddr.c_str());
        if(dwRetVal > 1) {
            printf("\tReceived %ld icmp message responses\n", dwRetVal);
            printf("\tInformation from the first response:\n");
        }
        else {
            printf("\tReceived %ld icmp message response\n", dwRetVal);
            printf("\tInformation from this response:\n");
        }
        // Error	C4996	'inet_ntoa': Use inet_ntop() or InetNtop()
        // instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable
        // deprecated API warnings
        printf("\t  Received from %s\n", inet_ntoa(ReplyAddr));
        printf("\t  Status = %ld\n", pEchoReply->Status);
        printf("\t  Roundtrip time = %ld milliseconds\n",
               pEchoReply->RoundTripTime);
    }
    else {
        printf("\tCall to IcmpSendEcho failed.\n");
        printf("\tIcmpSendEcho returned error: %ld\n", GetLastError());
        return 1;
    }
    return 0;
}

// https://stackoverflow.com/questions/20370920/convert-current-time-from-windows-to-unix-timestamp-in-c-or-c
unsigned long long fileTimeToUnixTime(FILETIME ft) {
    // Copy the low and high parts of FILETIME into a LARGE_INTEGER
    // This is so we can access the full 64-bits as an Int64 without causing an
    // alignment fault
    LARGE_INTEGER li;
    li.LowPart  = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;

    // Convert ticks since 1/1/1970 into seconds
    const __int64 UNIX_TIME_START =
        0x019DB1DED53E8000;  // January 1, 1970 (start of Unix epoch) in "ticks"
    const __int64 TICKS_PER_SECOND = 10000000;  // a tick is 100ns
    return static_cast<unsigned long long>((li.QuadPart - UNIX_TIME_START) /
                                           TICKS_PER_SECOND);
}

// https://docs.microsoft.com/en-us/windows/win32/sysinfo/retrieving-the-last-write-time
unsigned long long getFileCreationTime(const std::string& fname) {
    FILETIME  ftCreate, ftAccess, ftWrite;
    OFSTRUCT  buffer;
    HandlePtr hfile(
        CreateFile(CA2CT(fname.c_str()),  // file to open
                   GENERIC_READ,          // open for reading
                   FILE_SHARE_READ,       // share for reading
                   NULL,                  // default security
                   OPEN_EXISTING,         // existing file only
                   FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,  // normal file
                   NULL));  // no attr. template

    // Retrieve the file times for the file.
    if(!GetFileTime(hfile.get(), &ftCreate, &ftAccess, &ftWrite)) return FALSE;

    unsigned long long ftCreateUnix = fileTimeToUnixTime(ftCreate);

    return ftCreateUnix;
}

int main() {
    std::string fileName    = "C:\\xxx\\b.txt";

    unsigned long long t = getFileCreationTime(fileName);
    std::cout << fileName << " created at " << t << std::endl;

    std::string ipAddr = "127.0.0.1";
    std::cout << "ping " << ipAddr << " success? " << std::boolalpha
              << (ping(ipAddr) == 0) << std::endl;
    return 0;
}

/**
C:\xxx\b.txt created at 1637635015
ping 127.0.0.1  Sent icmp message to 127.0.0.1
        Received 1 icmp message response
        Information from this response:
          Received from 127.0.0.1
          Status = 7536761
          Roundtrip time = 6619252 milliseconds
 success? true
*/
