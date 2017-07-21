#pragma once
#include<screen.h>
#include<main.h>
class Game{
	public:
		Game(){ 
			this->playerX = 10;
			this->playerY = 10;
		};
		int playerX, playerY;
		int Update(int input);
	private:
		void movePlayer(int mx, int my);
};
