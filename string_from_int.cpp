// Example program
#include <iostream>

using namespace std;

int main()
{
    string s = "abc";
    
    //need to use to_string!
    s += to_string(123); //abc123
    
    //wrong!
    /**
    File "prun.py", line 67, in <module>                                                                                                         
    File "/usr/lib/python3.5/subprocess.py", line 947, in __init__                                                                               
    File "/usr/lib/python3.5/subprocess.py", line 1490, in _execute_child                                                                        
    BlockingIOError: [Errno 11] Resource temporarily unavailable 
    **/
    //s += 123; //abc{
    
    cout << s << endl;

    return 0;
}
