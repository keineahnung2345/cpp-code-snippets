#include <iostream>
#include <string> // string::rfind

using namespace std;

int main ()
{
  string str ("The sixth sick sheik's sixth sheep's sick.");
  string key ("sixth");

  //start from last char and go back
  cout << str.rfind(key) << endl; //23
  //start from 5th char and go back
  cout << str.rfind(key, 5) << endl;//4
  //start from 0 and go back->cannot find anything
  cout << (str.rfind(key, 0) == string::npos) << endl; //1
  
  size_t found = str.rfind(key);
  if (found!=string::npos)
    str.replace (found,key.length(),"seventh");

  cout << str << '\n';
  //The sixth sick sheik's seventh sheep's sick.
  //NOTE: the last "sixth" is replaced
  
  return 0;
}
