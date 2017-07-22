/* Copyright (C) 2017 Thomas Terry - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GPLv3 license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the GPLv3 license with
 * this file. If not, please visit : gnu.org
 */
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
