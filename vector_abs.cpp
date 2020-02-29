#include <iostream>
#include <vector>
#include <iterator> //ostream_iterator

//https://stackoverflow.com/questions/35638832/stdabs-with-stdtransform-not-working

int main(){
    std::vector<int> myvec = {-1,5,-9,4,3,-2};

    std::cout << "original: " << std::endl;
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    /*
    vector_abs.cpp:14:5: error: no matching function for call to 'transform'
        std::transform(myvec.begin(), myvec.end(), myvec.begin(), std::abs);
        ^~~~~~~~~~~~~~
    /Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm:1960:1: note: candidate template
          ignored: couldn't infer template argument '_UnaryOperation'
    transform(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __op)
    ^
    /Library/Developer/CommandLineTools/usr/include/c++/v1/algorithm:1970:1: note: candidate function
          template not viable: requires 5 arguments, but 4 were provided
    transform(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2,
    ^
    1 error generated.
    */
    //std::transform(myvec.begin(), myvec.end(), myvec.begin(), std::abs);

    //using a function pointer variable
    int (*iabs)(int) = &std::abs;
    std::transform(myvec.begin(), myvec.end(), myvec.begin(), iabs);

    std::cout << "'abs'ed: " << std::endl;
    std::copy(myvec.begin(), myvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

/*
original: 
-1 5 -9 4 3 -2 
'abs'ed: 
1 5 9 4 3 2
*/
