#pragma once
#include<game.h>
#include<curses.h>
class Screen{
	private:
		WINDOW *message, *stat, *map;
	public:
		Screen();
		~Screen();
		int getInput();
		void draw(Game *g);
};
