#include <iostream>
#include <limits>

using namespace std;

int main() {
	cout << tolower('A') << " " << (char)tolower('A') << endl; //97 a
	cout << toupper('a') << " " << (char)toupper('a') << endl; //65 A
	return 0;
}
