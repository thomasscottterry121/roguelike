#pragma once
#include<screen.h>
#include<main.h>
#include<stdlib.h>
typedef struct Player{
	int x,y;
	int Str,Int,Xp,Mp;
}Player;

class Game{
	public:
		Game();
		Player *player;
		int Update(int input);
		char **Map;
		bool **mWalk;
	private:
		void movePlayer(int mx, int my);
};
