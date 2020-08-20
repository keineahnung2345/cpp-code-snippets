#include <iostream>
#include <string>
#include <cctype> //isalnum
#include <algorithm> //remove_if

//https://stackoverflow.com/questions/6319872/how-to-strip-all-non-alphanumeric-characters-from-a-string-in-c

using namespace std;

int main()
{
    string s = "abc\rdef\nghi@%^&jkl[]mn";
    s.erase(std::remove_if(s.begin(), s.end(), 
        [](const char& c ) -> bool { return !std::isalnum(c); } ), 
        s.end());

    cout << s << endl;
    return 0;
}

//abcdefghijklmn
