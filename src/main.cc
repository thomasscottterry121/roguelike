#include<iostream>
#include<screen.h>
#include<game.h>
void Intro(){
	std::cout << "Welcome to spacehack" << std::endl;
	std::cout << "Press a key to play";
}

void Draw(Screen *s, Game *g){
	s->draw(g);
}

int GetInput(Screen *s){
	return s->getInput();
}
int Update(int input, Game *g){
	return g->Update(input);
}


int main(void){
        Intro();
	getch();
	Screen *s = new Screen();
	Game *g = new Game();
	Draw(s,g);
        while(Update(GetInput(s),g)){
                Draw(s, g);
        }
	delete s;
	delete g;
        return 0;
}
