#include <iostream>
#include <limits>

using namespace std;

int main() {
	cout << (isalpha('a') != 0) << endl; //1
	cout << (isalnum('1') != 0) << endl; //1
	cout << (isalnum('a') != 0) << endl; //1
	return 0;
}
