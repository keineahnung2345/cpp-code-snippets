#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}
    ~Point() {
        std::cout << "Point " << str() << " is destructed" << std::endl;
    }
    std::string str() {
        return "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    }

    void update(int x, int y) {
        x_ = x;
        y_ = y;
    }

private:
    int x_, y_;
};

class Triangle {
public:
    // unique_ptr as function argument
    Triangle(std::unique_ptr<Point> p1, std::unique_ptr<Point> p2,
             std::unique_ptr<Point> p3) {
        points.resize(3);
        points[0] = std::move(p1);
        points[1] = std::move(p2);
        points[2] = std::move(p3);
    }

    void print() {
        std::cout << points[0]->str() << ", " << points[1]->str() << ", "
                  << points[2]->str() << std::endl;
    }

    // return unique_ptr
    std::unique_ptr<Point> getPoint(int i) {
        i = std::min(std::max(i, 0), 2);
        // return points[i]; // compile error
        return std::move(points[i]);
    }

    bool checkPoint(int i) {
        i = std::min(std::max(i, 0), 2);
        return (points[i] == nullptr);
    }

private:
    std::vector<std::unique_ptr<Point>> points;
};

// https://stackoverflow.com/questions/4316727/returning-unique-ptr-from-functions
// https://stackoverflow.com/a/44889967/10651567
std::unique_ptr<Point> createUniquePtr() {
    std::unique_ptr<Point> p(new Point(7, 8));
    return p;  // works!
               // return std::move(p); // works!
}

int main() {
    // create unique_ptr
    std::unique_ptr<Point> p1(new Point(1, 2)), p2(new Point(3, 4)),
        p3(new Point(5, 6));
    // pass unique_ptr as argument
    // https://stackoverflow.com/questions/30905487/how-can-i-pass-stdunique-ptr-into-a-function
    Triangle t(std::move(p1), std::move(p2), std::move(p3));
    t.print();
    // after std::move, p1 will be null
    std::cout << "After std::move, p1 is null? " << std::boolalpha
              << (p1 == nullptr) << std::endl;

    // get unique_ptr from function
    std::unique_ptr<Point> point_unq_ptr = t.getPoint(0);
    std::cout << "Got triangle's first point: " << point_unq_ptr->str()
              << std::endl;
    std::cout << "Triangle's first point now is null? " << std::boolalpha
              << t.checkPoint(0) << std::endl;

    // get unique_ptr from function that creates it
    std::unique_ptr<Point> point_unq_ptr2 = createUniquePtr();
    std::cout << point_unq_ptr2->str() << std::endl;

    // unique_ptr from raw pointer
    std::unique_ptr<Point> point_unq_ptr3;
    point_unq_ptr3.reset(new Point(9, 10));
    std::cout << "Unique pointer from raw pointer: " << point_unq_ptr3->str()
              << std::endl;
    // dereference operator
    // https://stackoverflow.com/questions/17641682/replacing-the-content-of-the-shared-pointer
    (*point_unq_ptr3).update(11, 12);
    std::cout << "After updated: " << point_unq_ptr3->str() << std::endl;
    // release and delete the owned pointer
    point_unq_ptr3.reset(nullptr);
    // the above line is equivalent to the following:
    // https://stackoverflow.com/questions/25609457/does-unique-ptrrelease-call-the-destructor/25609507
    Point* raw = point_unq_ptr3.release();        // release
    delete raw; // and then delete

    // unique_ptr from object
    Point                  point(13, 14);
    std::unique_ptr<Point> point_unq_ptr4 = std::make_unique<Point>(point);
    std::cout << "Unique pointer from object: " << point_unq_ptr4->str()
              << std::endl;
    std::cout << "Original object: " << point.str()
              << std::endl;  // still exists

    return 0;
}

/**
(1, 2), (3, 4), (5, 6)
After std::move, p1 is null? true
Got triangle's first point: (1, 2)
Triangle's first point now is null? true
(7, 8)
Unique pointer from raw pointer: (9, 10)
After updated: (11, 12)
Point (11, 12) is destructed
Unique pointer from object: (13, 14)
Original object: (13, 14)
Point (13, 14) is destructed
Point (13, 14) is destructed
Point (7, 8) is destructed
Point (1, 2) is destructed
Point (3, 4) is destructed
Point (5, 6) is destructed
**/
