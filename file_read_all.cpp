#include <fstream>
#include <string>
#include <iostream>

//https://stackoverflow.com/questions/18398167/how-to-copy-a-txt-file-to-a-char-array-in-c
//https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

int main(){
    std::ifstream in("xxx.txt");
    
    // Method 1
    std::string content1((std::istreambuf_iterator<char>(in)), 
        std::istreambuf_iterator<char>());
    
    // Method 2
    std::stringstream ss;
    ss << in.rdbuf();
    std::string content2 = ss.str();
    
    std::cout << content1 << std::endl;
    std::cout << content2 << std::endl;
    
    in.close();
    return 0;
}
