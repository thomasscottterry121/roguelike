#pragma once
#include<screen.h>
#include<main.h>
#include<stdlib.h>
typedef struct Player{
	int x,y;
	int Str,Int,Xp,Mp;
}Player;

typedef struct Tile{
	char c;
	bool walk;
	bool door;
}Tile;

class Game{
	public:
		Game();
		Player *player;
		int Update(int input);
		char **Map;
		bool **mWalk;
		Tile **map;
	private:
		void movePlayer(int mx, int my);
		void OpenClose(int x, int y);
};
