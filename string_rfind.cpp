#include <iostream>
#include <string> // string::rfind

using namespace std;

int main ()
{
  string str ("The sixth sick sheik's sixth sheep's sick.");
  string key ("sixth");

  size_t found = str.rfind(key);
  if (found!=string::npos)
    str.replace (found,key.length(),"seventh");

  cout << str << '\n';
  //The sixth sick sheik's seventh sheep's sick.
  //NOTE: the last "sixth" is replaced
  
  return 0;
}
