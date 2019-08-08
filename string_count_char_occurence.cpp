#include <iostream>
#include <algorithm> //count

//https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c

using namespace std;

int main()
{

    string s = "a_b_c";
    size_t n = count(s.begin(), s.end(), '_');
    cout << "There are " << n << " '_' in " << s << endl;
    //There are 2 '_' in a_b_c

    return 0;
}
