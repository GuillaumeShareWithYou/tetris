#include "piece.h"
#include <algorithm>
#include <iostream>

using namespace app;
int main() {
    Piece p1;
    Point pt1(17, 21);
    Point pt2(2, 1);

    p1[0] = pt1;
    p1[1] = pt2;
    p1[2] = pt1;
    p1[3] = pt2;

    Piece p2(p1);
    p2[0] = *(new Point(55,66));

std::cout << "looping" << std::endl;
    
    std::for_each(p1.points, p1.points+4, [](Point& p){p.x++;});
    std::for_each(p1.points, p1.points+4, [](const Point& p){std::cout << p.x << std::endl;});
    
}