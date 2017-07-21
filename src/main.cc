#include<iostream>
#include<screen.h>
#include<game.h>
void Intro(){
	std::cout << "Welcome to spacehack" << std::endl;
	std::cout << "please press [Enter] to play";
	char c;
	std::cin >> c;
}

void Draw(Screen *s, Game *g){
	s->draw(g);
}

int GetInput(Screen *s){
	return s->getInput();
}
void Update(int input, Game *g){
	g->Update(input);
}


int main(void){
        Intro();
	Screen *s = new Screen();
	Game *g = new Game();
        while(1){
                Draw(s, g);
                Update(GetInput(s),g);
        }
        return 0;
}
