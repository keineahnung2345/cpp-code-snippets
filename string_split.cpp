#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/
//https://stackoverflow.com/questions/17807634/stringstream-duplicates-last-word

std::vector<std::string> string_split(std::string str, std::string delimiter){
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;
    
    //Style 1, need to deal with remaining string after the loop
    /*
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    */
    
    //Style 2, can deal with all tokens inside the while loop
    while(true){
        pos = str.find(delimiter);
        //works even if pos is string::npos
        token = str.substr(0, pos);
        result.push_back(token);
        if(pos == string::npos) break;
        //pos+1 equals to 0, so the line below can't handle this situation
        str.erase(0, pos+delimiter.length());
    }
    return result;
}

std::vector<std::string> string_split2(std::string str)
{  
    // Used to split string around spaces.
    std::istringstream ss(str);
    std::vector<std::string> result;
    std::string word;
   
    //need to check whether the reading success before using it
    while(ss >> word){
        result.push_back(word);
    }
   
    return result;
}

int main()
{
    std::string str = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    //Method 1
    for(std::string token : string_split(str, delimiter)){
        std::cout << token << std::endl;
    }
    std::cout << "=====================" << std::endl;

    //Method 2
    str = "Geeks for Geeks";
    std::vector<std::string> result = string_split2(str);
    std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}

/*
scott
tiger
mushroom
=====================
Geeks
for
Geeks
*/
