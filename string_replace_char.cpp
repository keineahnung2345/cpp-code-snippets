#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string

int main()
{
    string mystr = "2020/08/26";
    cout << mystr << " -> ";
    //the 3rd and 4th argument can only be a char, not a string
    replace(mystr.begin(), mystr.end(), '/', '-');
    cout << mystr << endl;
    
    return 0;
}

//2020/08/26 -> 2020-08-26
