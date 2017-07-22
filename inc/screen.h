#pragma once
class Game;
#include<game.h>
#include<curses.h>
struct Player;
class Screen{
	private:
		WINDOW *message, *stat, *map;
	public:
		Screen();
		~Screen();
		int getInput();
		void draw(int px, int py, char **map);
		void pMessage(char *message);
		void clearMessage();
		void refreshMessage();
		void printStat(struct Player *p);
};
