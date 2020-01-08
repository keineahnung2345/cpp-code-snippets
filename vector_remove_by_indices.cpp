#include <vector>
#include <iostream>
#include <algorithm>

//https://stackoverflow.com/questions/35055227/how-to-erase-multiple-elements-from-stdvector-by-index-using-erase-function?rq=1
//https://stackoverflow.com/questions/29188668/cout-and-char-address

int main(){
    std::vector<int> removelist = {1,3,4,5};
    std::vector<char> myvec = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};

    for(int i = 0; i < myvec.size(); i++){
        std::cout << myvec[i];
    }
    std::cout << std::endl;

    //[&]: so "removelist" and "myvec" can be captured
    //const char&: we need the "&" so its address is correct
    myvec.erase(std::remove_if(myvec.begin(), myvec.end(), [&](const char& c) {
      auto idx = ((void*)&c - (void*)&*myvec.begin());
      std::cout << (void*)&c << " - " << (void*)&*myvec.begin() << " = " << idx << std::endl;
      return std::find(removelist.begin(), removelist.end(), idx) != removelist.end();
    }), myvec.end());
    //remove_if removes some elements from the myvec, but myvec.size() doesn't change
    //we need the outer "myvec.erase(my_vec_new_end, myvec.end())" to resize it

    for(int i = 0; i < myvec.size(); i++){
        std::cout << myvec[i];
    }
    std::cout << std::endl;
    return 0;
}
