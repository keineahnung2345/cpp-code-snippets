#include <stdio.h>
#include <assert.h>

//https://www.geeksforgeeks.org/assertions-cc/

int main()
{
    int x = 7;

    /*  Some big code in between and let's say x  
       is accidentally changed to 9  */
    x = 9;

    // Programmer assumes x to be 7 in rest of the code 
    assert(x==7);

    /* Rest of the code */

    return 0;
}
