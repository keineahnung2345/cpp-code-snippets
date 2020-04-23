#include <vector>
#include <iostream>

//https://stackoverflow.com/questions/9062082/switch-statements-with-strongly-typed-enumerations

enum class FB{
    X = -1, //don't care
    B, //background
    F //foreground
};

int main(){
    std::vector<FB> cross = {
        FB::X, FB::F, FB::X, 
        FB::F, FB::F, FB::F,
        FB::X, FB::F, FB::X};
    
    for(int i = 0; i < cross.size(); i++){
        switch(cross[i]){
            case FB::F:
                std::cout << i << " is foreground" << std::endl;
                break;
            case FB::B:
                std::cout << i << " is background" << std::endl;
                break;
            case FB::X:
                std::cout << "we don't care " << i << std::endl;
                break;
            default:
                std::cout << "invalid enum value!" << std::endl;
                break;
        }
    }

    return 0;
}

/*
we don't care 0
1 is foreground
we don't care 2
3 is foreground
4 is foreground
5 is foreground
we don't care 6
7 is foreground
we don't care 8
*/
