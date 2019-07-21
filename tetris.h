#pragma once
#include "board.h"
#include <SFML/Graphics.hpp>
#include "iostream"

namespace app {

   
    
 
    class Tetris {

        public:
            Board board;        
            int  dx;
            bool rotate;
            int  colorNum;
            Piece currentPiece;
            bool gameOver;
            int lines;
            static int figures[7][4];
            void init();
            void start();
            void movePiece();
            void rotatePiece();
            void fallingPiece();

        private:
            int timer;
            int delay;
            void spawnPiece();

            

    };

};
