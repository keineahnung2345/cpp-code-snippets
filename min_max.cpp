#include <iostream>
#include <algorithm>

using namespace std;

//https://stackoverflow.com/questions/9424173/find-the-smallest-amongst-3-numbers-in-c

int main() {
	cout << min(1,2) << endl; //1
	cout << max(1,2) << endl; //2
	//for multiple arguments, add {} around them!
	cout << min({1,2,3,4}) << endl; //1
	return 0;
}
