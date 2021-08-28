#include <iostream>

//https://openhome.cc/Gossip/CppGossip/Using.html
//https://openhome.cc/Gossip/CppGossip/Inheritance.html
//it demos 1. inheritance from grandpa class rather than parent class 
//2. inherit protected member of grandpa class as a public member

class Shape{
protected:
    float area;
public:
    void printArea() {
        std::cout << "I'm Shape with area = " << area << std::endl;
    }
};

//note: public inheritance
class Rectangle : public Shape{
protected:
    using Shape::area;
public:
    void printArea() {
        std::cout << "I'm Rectangle with area = " << area << std::endl;
    }

};

class Square : public Rectangle{
public:
    using Shape::area;
    //note: no () after function name
    using Shape::printArea;
};

int main(){
    Square sqr;
    //"area" becomes a public member of "Square"
    sqr.area = 9;
    //it uses "printArea" from "Shape"
    sqr.printArea();
    //I'm Shape with area = 9

    return 0;
}
