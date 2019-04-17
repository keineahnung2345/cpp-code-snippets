#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = {1,2,3};
	cout << "last element: " <<  v.back() << endl;
	v.back() = 5;
	cout << "last element: " << v.back() << endl;
	return 0;
}
