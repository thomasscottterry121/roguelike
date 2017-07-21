#pragma once
class Game;
#include<game.h>
#include<curses.h>

class Screen{
	private:
		WINDOW *message, *stat, *map;
	public:
		Screen();
		~Screen();
		int getInput();
		void draw(int px, int py);
		void pMessage(char *message);
		void clearMessage();
		void refreshMessage();
};
