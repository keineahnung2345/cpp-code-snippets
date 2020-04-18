#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <iterator> //ostream_iterator

class Point{
    public:
        int x;
        int y;
        Point(int x_in, int y_in){
            x = x_in;
            y = y_in;
        };
        ~Point(){};
};

static bool point_comparator(Point &a, Point &b)
{
    //the smaller the former
    /*
    Note that we must use "<", not "<=" here,
    because the predicate must satisfy Strict Weak Ordering,
    which includes the rule "Irreflexivity: f(x, x) must be false."
    Otherwise, there will be a heap-buffer-overflow error.
    https://www.boost.org/sgi/stl/StrictWeakOrdering.html
    */
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main()
{
    Point a(2,3);
    Point b(1,4);
    
    std::cout << "(2, 3) smaller than (1, 4): " << point_comparator(a, b) << std::endl;
    
    std::vector<Point> v = {Point(2,3), Point(1,4), Point(0,5), Point(-1,6)};
    
    std::sort(v.begin(), v.end(), point_comparator);
    
    std::cout << "sorted vector of Point: " << std::endl;
    for(std::vector<Point>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << it->x << " " << it->y << std::endl;
    }

    return 0;
}
