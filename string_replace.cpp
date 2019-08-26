#include <iostream>
using namespace std;

int main() {
	string s = "this sentence contains a word toreplace!";
	cout << "old string: " << s << endl; //old string: this sentence contains a word toreplace!
	
	string toReplace("toreplace");
	string newText("newtext");
	
	size_t pos = s.find(toReplace);
	//replace the first occurence
	s.replace(pos, toReplace.length(), newText);
	
	cout << "new string: " << s << endl; //new string: this sentence contains a word newtext!
	return 0;
}
