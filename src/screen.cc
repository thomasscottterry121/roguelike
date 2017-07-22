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

void Screen::draw(int px, int py, char **map){
	wclear(this->map);
	for(int y = 0; y < 20; y++){
		mvwprintw(this->map,y,0,map[y]);
	}
        wattron(this->map,COLOR_PAIR(1));
        mvwprintw(this->map,py, px, "@");
        wattroff(this->map, COLOR_PAIR(1));

	wrefresh(stdscr);
	wrefresh(this->map);
}

void Screen::pMessage(char *message){
	mvwprintw(this->message,0,1,message);
}

void Screen::refreshMessage(){
	wrefresh(this->message);
}

void Screen::clearMessage(){
	wclear(this->message);
}

void Screen::printStat(Player *p){
	wclear(this->stat);
	mvwprintw(this->stat,0,1,"Strength: %d Intelligience: %d Magic: %d", p->Str, p->Int, p->Mp);
	wrefresh(this->stat);
}
