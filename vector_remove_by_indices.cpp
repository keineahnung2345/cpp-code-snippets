#include <vector>
#include <iostream>
#include <algorithm>

//https://stackoverflow.com/questions/35055227/how-to-erase-multiple-elements-from-stdvector-by-index-using-erase-function?rq=1
//https://stackoverflow.com/questions/29188668/cout-and-char-address

template<typename T>
void remove_by_indices(std::vector<T>& myvec, std::vector<int>& removelist){
    //[&]: so "removelist" and "myvec" can be captured
    //const char&: we need the "&" so its address is correct
    myvec.erase(std::remove_if(myvec.begin(), myvec.end(), [&](const T& c) {
      //https://stackoverflow.com/questions/28846270/casting-void-pointer-to-long-type-not-pointer-long
      auto idx = ((long)(void*)&c - (long)(void*)&*myvec.begin());
      //error: invalid use of ‘void’
      //auto idx = ((void*)&c - (void*)&*myvec.begin());
      //std::cout << (void*)&c << " - " << (void*)&*myvec.begin() << " = " << idx << std::endl;
      return std::find(removelist.begin(), removelist.end(), idx) != removelist.end();
    }), myvec.end());
    //remove_if removes some elements from the myvec, but myvec.size() doesn't change
    //we need the outer "myvec.erase(my_vec_new_end, myvec.end())" to resize it
}


int main(){
    std::vector<int> removelist = {1,3,4,5};
    std::vector<char> myvec = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};

    for(int i = 0; i < myvec.size(); i++){
        std::cout << myvec[i];
    }
    std::cout << std::endl;

    remove_by_indices(myvec, removelist);

    for(int i = 0; i < myvec.size(); i++){
        std::cout << myvec[i];
    }
    std::cout << std::endl;
    return 0;
}

/*
helloworld
hlorld
*/
