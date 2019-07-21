#pragma once
#define WIDTH 10
#define HEIGHT 20
#include "piece.h"

namespace app {


    class Board {

        public:
            Board();
            int pieces[HEIGHT][WIDTH];
            bool collideWithPiece(Piece& piece);
            void debug();
            int checkLines();
    };

};