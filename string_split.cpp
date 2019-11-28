#include <iostream>
#include <vector>
#include <string>

//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c

std::vector<std::string> string_split(std::string str, std::string delimiter){
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}

int main()
{
    std::string str = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";
    
    for(std::string token : string_split(str, delimiter)){
        std::cout << token << std::endl;
    }

    return 0;
}
