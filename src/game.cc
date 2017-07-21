#include<game.h>
#include<screen.h>
int Game::Update(int input){
	switch(input){
		case '4':
			this->movePlayer(-1,0);
			break;
		case '8':
			this->movePlayer(0,-1);
			break;
		case '6':
			this->movePlayer(1,0);
			break;
		case '2':
			this->movePlayer(0,1);
			break;
		case 'q':
			return 0;
		default:
			break;
	}
	return 1;
}

void Game::movePlayer(int mx, int my){
	if(this->playerX + mx < 80 && this->playerY + my < 19 &&
		 this->playerX + mx > -1 && this->playerY+my > -1){
		this->playerX+=mx;
		this->playerY+=my;
	}
}
