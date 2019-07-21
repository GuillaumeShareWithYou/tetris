#include <time.h>
#include "tetris.h"
using namespace sf;
#define MAX_DELAY .3

 
int main()
{
    srand(time(0));	 

	RenderWindow window(VideoMode(600,600.0 * ( 320.0 / 480)), "The Game!");

    Texture t1,t2,t3;
	t1.loadFromFile("images/tiles.png");
	t2.loadFromFile("images/background.png");
	t3.loadFromFile("images/frame.png");

	Sprite s(t1), background(t2), frame(t3);

	app::Tetris game; 
	game.init();

	float timer=0,delay=MAX_DELAY; 

	game.start();
	sf::Clock clock;

    while (!game.gameOver && window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed || e.key.code == Keyboard::Escape)
                window.close();

			if (e.type == Event::KeyPressed){   
			  if (e.key.code==Keyboard::Up) game.rotate =    1;
			  else if (e.key.code==Keyboard::Left) game.dx = -1;
			  else if (e.key.code==Keyboard::Right) game.dx= 1;
			  else if(e.key.code == Keyboard::D) game.board.debug();
            }
		}

	if (Keyboard::isKeyPressed(Keyboard::Down)) delay=0.05;

	game.movePiece();
	
	game.rotatePiece();

	///////Tick//////
	if (timer>delay)
	  {
		game.fallingPiece();
	  	timer=0;
	  }


    /////////draw//////////
    window.clear(Color::White);	
    window.draw(background);
		  
	for (int i=0;i<HEIGHT;i++)
	 for (int j=0;j<WIDTH;j++)
	   {
         if (game.board.pieces[i][j]==0) continue;
		 s.setTextureRect(IntRect(game.board.pieces[i][j]*18,0,18,18));
		 s.setPosition(j*18,i*18);
		 s.move(28,31); //offset
		 window.draw(s);
	   }

	for (int i=0;i<4;i++)
	  {
		s.setTextureRect(IntRect(game.colorNum*18,0,18,18));
		s.setPosition(game.currentPiece[i].x*18,game.currentPiece[i].y*18);
		s.move(28,31); //offset
		window.draw(s);
	  }

	window.draw(frame);
 	window.display();
	delay = MAX_DELAY;
	}

 	std::cout << "Game over with " << game.lines << " lines." << std::endl;
	window.close();

    return 0;
}