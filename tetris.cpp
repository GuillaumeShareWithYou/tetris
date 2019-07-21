#include "tetris.h"

namespace app {
    
   
   int Tetris::figures[7][4] = {
        1, 3, 5, 7, // I
        2, 4, 5, 7, // Z
        3, 5, 4, 6, // S
        3, 5, 4, 7, // T
        2, 3, 5, 7, // L
        3, 5, 7, 6, // J
        2, 3, 4, 5  // O
    };

    
void Tetris::init(){
    this->delay = .3;
    this->dx = 0;
    this->rotate = 0;
    this->timer = 0;
    this->gameOver = false;
    this->lines = 0;
}

void Tetris::start(){
    this->spawnPiece();
}

void Tetris::spawnPiece(){
         this->colorNum = 1 + rand() % 7; // random color, 0 is not a color
		 int n = rand() % 7; // random figure
		 for (int i=0;i<4;i++) {
		    currentPiece[i].x = figures[n][i] % 2 + (WIDTH / 2 - 1); // offset to the middle of the board
		    currentPiece[i].y = figures[n][i] / 2;
         }
		
}

void Tetris::movePiece() {
    if(this->dx == 0) return;
    Piece temp(currentPiece);
    std::for_each(currentPiece.points, currentPiece.points + 4, [&](Point& p){
        p.x += this->dx;
    });
    if(board.collideWithPiece(currentPiece)) {
        std::cout << "collisions" << std::endl;
        currentPiece = temp;
    } else {
        std::cout << "pas de collisions" << std::endl;
    }
    this->dx = 0;
}

void Tetris::rotatePiece(){
    if(rotate){
        Piece temp(currentPiece);

    	app::Point p = currentPiece[1]; //center of rotation
		for (int i=0;i<4;i++)
		  {
			int x = currentPiece[i].y-p.y;
			int y = currentPiece[i].x-p.x;
			currentPiece[i].x = p.x - x;
			currentPiece[i].y = p.y + y;
	 	  }        

        if(board.collideWithPiece(currentPiece)) currentPiece = temp;
        rotate = 0;
    }
    
}

void Tetris::fallingPiece(){
    Piece temp(currentPiece);
    std::for_each(currentPiece.points, currentPiece.points + 4 , [](Point& p){
        p.y++;
    });
    if(board.collideWithPiece(currentPiece)) {
              
        for (int i = 0; i < 4; i++)
        {
            board.pieces[temp[i].y][temp[i].x] = colorNum;
        }
        this->lines += board.checkLines();

        spawnPiece();
        if(board.collideWithPiece(currentPiece)) this->gameOver = true;
    }
}

}