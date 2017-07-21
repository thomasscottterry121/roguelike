#include<screen.h>

Screen::Screen(){
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	this->message = newwin(2,80,0,0);
	this->map = newwin(19, 80, 2, 0);
	this->stat = newwin(3, 80, 21, 0);
	wclear(stdscr);
	wrefresh(stdscr);
	wclear(this->message);
	wclear(this->stat);
	wclear(this->map);
	wrefresh(this->map);
	wrefresh(this->stat);
	wrefresh(this->message);
}

Screen::~Screen(){
	delwin( this->message);
	delwin( this->map);
	delwin( this->stat);
	nocbreak();
	echo();
	curs_set(1);
	endwin();
}

int Screen::getInput(){
	return getch();
}

void Screen::draw(Game *g){
	wclear(this->map);
	attron(COLOR_PAIR(1));
	mvwprintw(this->map,g->playerY, g->playerX, "@");
	attroff(COLOR_PAIR(1));
	wrefresh(stdscr);
	wrefresh(this->map);
}

