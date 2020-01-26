#include <iostream>
#include <vector>

class Rectangle{
public:
    Rectangle(int h, int w): height(h), width(w){
        area = height * width;
    };

    int get_area(){
        return area;
    }
private:
    int area;
    int height;
    int width;
};

int main(){
    std::vector<Rectangle> rects;

    rects.push_back(Rectangle(10,20));
    rects.emplace_back(20,30);

    std::cout << rects[0].get_area() << std::endl; //200
    std::cout << rects[1].get_area() << std::endl; //600
    
    return 0;
}
