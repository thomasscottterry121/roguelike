/* Copyright (C) 2017 Thomas Terry - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GPLv3 license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the GPLv3 license with
 * this file. If not, please visit : gnu.org
 */
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
		void draw(int px, int py, struct Tile **map);
		void pMessage(char *message);
		void clearMessage();
		void refreshMessage();
		void printStat(struct Player *p);
};
