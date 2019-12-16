#include <iostream>
#include <string>

//http://www.cplusplus.com/reference/string/string/find_first_of/
//find_first_of: find char that matches any of its argument

int main(){
    std::string s = "1-2--3--4-5--6--7";
    int index = -1;
    std::cout << "string length: " << s.size() << std::endl;
    do{
        index = s.find_first_of("0123456789", index + 1);
        if(index != -1){
            std::cout << index << std::endl;
        }
    }while(index != -1);

    return 0;
}
