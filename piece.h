#pragma once
namespace app {

    struct Point {
        int x = 0, y = 0;
        Point(){}
        Point(int _x, int _y): x(_x), y(_y){}
        Point& operator=(Point& other){
            x = other.x;
            y = other.y;
            return *this;
        }
    };

    class Piece {
        private:
        public:
           Point* points = new Point[4]();
            Piece();
            Piece(Piece&);
            Point& operator[](int i);
            Piece& operator=(Piece& p);
    };
} // namespace app


