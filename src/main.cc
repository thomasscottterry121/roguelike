#include<iostream>
#include<screen.h>
#include<game.h>
#include<main.h>
Screen *s;
void Intro(){
	std::cout << "Welcome to spacehack" << std::endl;
}

void Draw(Screen *s, Game *g){
	s->draw(g->playerX, g->playerY);
}

int GetInput(Screen *s){
	return s->getInput();
}
int Update(int input, Game *g){
	return g->Update(input);
}


int main(void){
        Intro();

	s = new Screen();
	Game *g = new Game();

	Draw(s,g);
	do{
                Draw(s, g);
        }while( Update( GetInput(s) , g) );


	delete s;
	delete g;
        return 0;
}

void screenMessage(char *message){
	s->clearMessage();
	s->pMessage(message);
	s->refreshMessage();
}
