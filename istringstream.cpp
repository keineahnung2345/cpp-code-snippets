#include <iostream>
#include <sstream> //stringstream, istringstream, ostringstream

using namespace std;

int main()
{
    string sentence = "hello world how are you";
    istringstream is(sentence);
    string word;
    
    while(is >> word){
    	cout << word << endl;
    }
    
    /**
    hello
    world
    how
    are
    you
    **/
    
    return 0;
}
