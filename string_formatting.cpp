#include <string>
#include <iostream>
#include <sstream> //std::ostringstream
#include <iomanip> //std::setw, std::setfill

//https://stackoverflow.com/questions/6143824/add-leading-zeros-to-string-without-sprintf
//https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf

int main(){
    int hour = 3, minute = 1;
    std::ostringstream ss;
    ss << hour << ":" << std::setw(2) << std::setfill('0') << minute;
    std::string str1 = ss.str();
    std::cout << str1 << std::endl; //3:01
    
    //formatting like python
    std::string mystr = "My name is %s and I am %d years old.";
    char buf[50];
    sprintf(buf, mystr.c_str(), "Mary", 6);
    std::cout << mystr << std::endl;
    
    return 0;
}
