#include <windows.h>
#include <atlbase.h>
#include <atlconv.h> // CA2CT

int renameFile(const std::string& oldName, const std::string& newName) {
    // https://stackoverflow.com/questions/3020725/char-array-to-lpctstr
    int   retVal = 0;  // return 0 means success
    CA2CT ctOldName(oldName.c_str());
    CA2CT ctNewName(newName.c_str());
    // MoveFile returns 0 on failure
    if(MoveFile(ctOldName, ctNewName) == 0) retVal = -1;
    return retVal;
};

int main() {
    // need full path?
    std::string oldFileName =
        "C:\\Users\\xxx\\a.txt";
    std::string newFileName =
        "C:\\Users\\xxx\\b.txt";
    bool renameSuccess = (renameFile(oldFileName, newFileName) == 0);
    std::cout << "rename success? " << std::boolalpha << renameSuccess << std::endl;
    return 0;
}
