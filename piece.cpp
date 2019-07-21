#include "piece.h"

namespace app
{
    Piece::Piece(){}

    Piece::Piece(Piece& other){
        *this = other;
    }


    Point& Piece::operator[](int i){return points[i];}

    Piece& Piece::operator=(Piece& other) { 
        for(int i = 0; i < 4; ++i)
            points[i] = other[i];
        return *this;
    }

} // namespace app

