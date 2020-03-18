#include <algorithm> //find
#include <iostream>
#include <vector>

//https://stackoverflow.com/questions/24997910/get-index-in-vector-from-reverse-iterator
//https://stackoverflow.com/questions/42638952/using-stdfind-with-reverse-iterators

int main(){
    std::vector<int> myvec = {3,4,9,8,3,2,1};
    int tofind = 3;
	
    std::vector<int>::iterator it = std::find(myvec.begin(), myvec.end(), tofind);
    if(it != myvec.end()){
        std::cout << "find " << tofind << " from left at " << (it - myvec.begin()) << std::endl;
    }
	
    std::vector<int>::reverse_iterator rit = std::find(myvec.rbegin(), myvec.rend(), tofind);
    if(rit != myvec.rend()){
        //these two styles generate same result
        //int idx = std::distance(begin(myvec), rit.base()) - 1;
        int idx = (myvec.rend() - rit - 1);
        std::cout << "find " << tofind << " from right at " << (myvec.rend() - rit - 1) << std::endl;
    }else{
        std::cout << "not found!" << std::endl;
    }
}

/*
find 3 from left at 0
find 3 from right at 4
*/
