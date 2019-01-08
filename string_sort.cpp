#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s = "erhsdvfwehtj4hte";
    cout << s << endl;
    sort(s.begin(), s.end());
    cout << s << endl;

    return 0;
}
