#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = {1,2,3};
	
	for(int e : v) cout << e << " ";
	cout << endl;
	
	//remove 2
	v.erase(v.begin()+1);
	
	for(int e : v) cout << e << " ";
	cout << endl;
	
	return 0;
}
