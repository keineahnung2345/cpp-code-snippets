#include <iostream>
#include <boost/intrusive_ptr.hpp>
#include "intrusive_ptr_base.hpp"

class Rectangle : public intrusive_ptr_base<Rectangle> {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    ~Rectangle() { std::cout << "Rectangle destructor" << std::endl; }
    int getArea() { return width * height; }
private:
    int width;
    int height;
};

int main(){
    Rectangle* rectp = new Rectangle(5, 3);
    boost::intrusive_ptr<Rectangle> rectsp1(rectp);
    std::cout << "refcount: " << rectsp1->refcount() << std::endl;
    boost::intrusive_ptr<Rectangle> rectsp2(rectp);
    std::cout << "refcount: " << rectsp1->refcount() << std::endl;
    //rectsp1.reset(rectp);
    std::cout << rectsp1->getArea() << std::endl;
    return 0;
}

/*
  Default constructor 
  intrusive_ptr_add_ref...
refcount: 1
  intrusive_ptr_add_ref...
refcount: 2
15
  intrusive_ptr_release...
  intrusive_ptr_release...
Rectangle destructor
*/
