#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

//g++ remove_file.cpp -lboost_filesystem -lboost_system
/*-lboost_system is required, otherwise there will be:
//usr/bin/ld: /tmp/ccDwa2Ug.o: undefined reference to symbol '_ZN5boost6system15system_categoryEv'
//usr/lib/x86_64-linux-gnu/libboost_system.so.1.58.0: error adding symbols: DSO missing from command line
collect2: error: ld returned 1 exit status
*/

//https://stackoverflow.com/questions/19944753/linking-compiling-a-program-that-uses-boost-filesystem-hpp

int main(){
    std::string fname = "tmp.txt";
    boost::filesystem::path fname_path(fname);
    //return true if the file exist, false if not exist
    bool success = boost::filesystem::remove(fname_path);
    std::cout << "remove " << fname << "?: ";
    std::cout << (success ? "true" : "false") << std::endl;
    return 0;
}
