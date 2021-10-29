#include <stdio.h>
#include <string.h>

//https://stackoverflow.com/questions/18972258/index-of-nth-occurrence-of-the-string

int strpos(char* haystack, char* needle, int nth){
     //nth is 1-based
    char* res = haystack;
    for(int i = 1; i <= nth; i++){
        res = strstr(res, needle);
        if (!res){
            return -1;
        }else if(i != nth){
            res++;
        }
    }
    return res - haystack;
}

int main()
{
    char* haystack = "The rain in Spain falls mainly on the plain";
    char* needle = "ain";
    int nth = 2;
    
    int pos = strpos(haystack, needle, 2);
    
    printf("%dnd '%s' in '%s': %d", nth, needle, haystack, pos);
    
    return 0;
}

//2nd 'ain' in 'The rain in Spain falls mainly on the plain': 14
