#include <iostream>
#include <sstream>

// https://stackoverflow.com/questions/9197358/ofstream-reset-precision

int main() {
   std::stringstream ss;
   ss << 1.12345 << " ";
 
   std::streamsize p = ss.precision();
 
   ss.precision(2);
   ss << 1.12345 << " ";
 
   ss.precision(p);
   ss << 1.12345;
   
   cout << ss.str();
}

//1.12345 1.1 1.12345
