#include <iostream>
#include <fstream>
using namespace std;

//http://www.cplusplus.com/doc/tutorial/files/

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
