#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
int main()
{
    std::ifstream infile("a.txt");
    
    //Method 1
    int a, b;
    
    while (infile >> a >> b)
    {
        std::cout << a << " " <<  b << std::endl;
    }
    
    infile.close();
    
    //Method 2
    infile.open ("a.txt", std::ifstream::in);

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { break; } // error
    
        std::cout << a << " " << b << std::endl;
    }

    return 0;
}
