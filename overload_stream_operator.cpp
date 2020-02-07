#include <iostream>
using namespace std;

//https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

class Complex
{ 
private: 
     int real, imag;
public: 
     Complex(int r = 0, int i =0)
     {  real = r;   imag = i; } 
     friend ostream & operator << (ostream &out, const Complex &c);
     friend istream & operator >> (istream &in,  Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
     out << c.real;
     out << "+i" << c.imag << endl;
     return out;
}

istream & operator >> (istream &in,  Complex &c)
{
     cout << "Enter Real Part ";
     in >> c.real;
     cout << "Enter Imagenory Part ";
     in >> c.imag;
     return in;
}

int main()
{
    Complex c1;
    cin >> c1;
    cout << "The complex object is ";
    cout << c1;
    return 0;
}
