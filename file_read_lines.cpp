#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
//https://stackoverflow.com/questions/43956124/c-while-loop-to-read-from-input-file
int main()
{
    std::ifstream infile("a.txt");
    
    //Method 1
    int a, b;
    
    while (infile >> a >> b)
    {
        std::cout << a << " " <<  b << std::endl;
    }
    
    /*
    note that using:
    while(infile){
        infile >> a;
        infile >> b;
    }
    will give you one extra line!
    that's because EOF will be set "after" you read to end of the file
    */
    
    infile.close();
    
    //Method 2
    infile.open ("a.txt", std::ifstream::in);

    //https://stackoverflow.com/questions/37957080/can-i-use-2-or-more-delimiters-in-c-function-getline
    //in Windows, we need both '\n' and '\r' as delimeter!
    std::string line;
    while (std::getline(infile, line, '\n'))
    {
        std::stringstream ss(line);
        while(std::getline(ss, line, '\r')){
            std::istringstream iss(line);
            int a, b;
            if (!(iss >> a >> b)) { break; } // error

            std::cout << a << " " << b << std::endl;
        }
    }

    return 0;
}
