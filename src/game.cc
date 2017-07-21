#include<game.h>
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
	if(this->playerX + mx < 79 && this->playerY + my < 20 &&
		 this->playerX + mx > 0 && this->playerY+my > 0){
		this->playerX+=mx;
		this->playerY+=my;
	}
}
