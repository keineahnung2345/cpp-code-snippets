#include <iostream>

using namespace std;

int main()
{
    string str = "hello goodbye and hello";
    string key = "hello";
    
    cout << str.rfind(key) << endl; //18
    //https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-stdstring-starts-with-a-certain-string-and-convert-a
    //c++ don't have str.startswith, so we use str.rfind(key, 0)==0 to simulate str.startswith
    //check if str starts with key
    cout << (str.rfind(key, 0)==0) << endl; //1
    
    return 0;
}
