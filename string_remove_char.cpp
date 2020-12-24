#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/3882304/replace-remove-character-in-string
//http://www.cplusplus.com/reference/algorithm/remove/
//https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus

int main()
{
    string mystr = "2020/08/26";
    cout << mystr << " -> ";
    
    //method 1
    //the 3rd argument can only be a char, not a string
    auto it = remove(mystr.begin(), mystr.end(), '/');
    string mystr_removed = string(mystr.begin(), it);
    cout << mystr_removed << endl;
    
    //method 2
    mystr = "2020/08/26";
    cout << mystr << " -> ";
    mystr.erase(remove(mystr.begin(), mystr.end(), '/'), mystr.end());
    cout << mystr << endl;
    
    return 0;
}

//2020/08/26 -> 20200826
