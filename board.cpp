#include "board.h"
#include <iostream>
namespace app {

Board::Board(){
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            this->pieces[i][j] = 0;
        }
    }
    
}

int Board::checkLines(){

   int nbLines = 0; 
    for(int k = HEIGHT - 1; k > 0;){

        int count = 0;
        for (int i = 0; i < WIDTH; ++i)
        {
            if(this->pieces[k][i]) ++count;
        }
        if(count == WIDTH) {
            ++nbLines;
            for (int y = k; y > 0; --y)
            {
                for (int x = 0; x < WIDTH; ++x)
                {
                    this->pieces[y][x] = this->pieces[y-1][x];
                }
            }

        } else {
            --k;
        }
        
    }
    return nbLines;
}
void Board::debug(){
      for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
           std::cout << this->pieces[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

    bool Board::collideWithPiece(Piece& piece){

        for(int i = 0; i < 4; ++i){
            if(piece[i].x < 0 || piece[i].x >= WIDTH || piece[i].y >= HEIGHT || pieces[piece[i].y][piece[i].x] != 0 ){
                return true;
            }
        }
        return false;
    }

}