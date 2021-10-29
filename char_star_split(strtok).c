#include <cstdio>
#include <cstring>

//https://stackoverflow.com/questions/10349270/c-split-a-char-array-into-different-variables
//https://stackoverflow.com/questions/6684976/how-do-i-print-escape-characters-as-characters

int main()
{
    char input[16] = "abc\rd\refg";
    
    for(char& c : input){
        if(c == '\r'){
            printf("\\r");
        }else{
            printf("%c", c);
        }
    }
    printf("\n");
    
    char* delimeter = "\r";
    char* p;

    p = strtok(input, delimeter);


