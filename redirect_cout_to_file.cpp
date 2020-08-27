#include <iostream>

using namespace std;

//https://stackoverflow.com/questions/29154056/redirect-stdout-to-a-file

int main()
{
    char* logfile = "stdout.txt";

    FILE* fptr = freopen(logfile, "w", stdout);
    std::cout << "output 1" << std::endl;
    fclose(fptr);

    //after fptr being closed, this cannot std::cout cannot be used
    //std::cout << "output something after closing fptr" << std::endl;

    logfile = "stdout2.txt";
    fptr = freopen(logfile, "w", stdout);
    std::cout << "output 2" << std::endl;
    fclose(fptr);

    return 0;
}
