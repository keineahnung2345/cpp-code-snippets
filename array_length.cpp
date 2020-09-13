#include <iostream>
#include <set>

using namespace std;

//https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array

//Method 1: will return wrong answer
template<class T>
int get_length(T* arr){
    // cout << arr[0] << endl;
    // cout << "size of total array: " << sizeof(arr) << endl;
    // cout << "size of an element: "  << sizeof(*arr) << endl;
    // cout << "array length: "   << sizeof(arr)/sizeof(*arr) << endl;
    return sizeof(arr)/sizeof(*arr);
}

//Method 2: correct
template<class T, size_t N>
constexpr size_t size(T (&)[N]) { return N; }

int main()
{
    char arrA[] = {'A', 'B', 'C'};
    int arrB[] = {1, 4, 6, 2, 1};
    cout << get_length(arrA) << endl; //8, wrong!
    cout << get_length(arrB) << endl; //2, wrong!
    cout << size(arrA) << endl; //3
    cout << size(arrB) << endl; //5
    return 0;
}
