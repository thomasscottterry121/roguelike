#include<game.h>
#include<screen.h>


int Game::Update(int input){
	screenMessage((char *)" ");
	switch(input){
		case 1:
			screenMessage((char *)"You enterd a ctrl key");
			break;
		case '4':
		case 'h':
			this->movePlayer(-1,0);
			break;
		case '1':
		case 'b':
			this->movePlayer(-1,1);
			break;
		case '8':
		case 'k':
			this->movePlayer(0,-1);
			break;
		case '7':
		case 'y':
			this->movePlayer(-1,-1);
			break;
		case '6':
		case 'l':
			this->movePlayer(1,0);
			break;
		case '9':
		case 'u':
			this->movePlayer(1,-1);
			break;
		case '2':
		case 'j':
			this->movePlayer(0,1);
			break;
		case '3':
		case 'n':
			this->movePlayer(1,1);
			break;
		case 'q':
			screenMessage((char *)"You drink a potion!");
			break;
		case 'Q':
			screenMessage((char *)"You quiver some arrows");
			break;
		case 27:
			return 0;
		default:
			screenMessage((char *)"Key not implemented");
			break;
	}
	return 1;
}

void Game::movePlayer(int mx, int my){
	if(this->player->x + mx < 80 && this->player->y + my < 19 &&
		 this->player->x + mx > -1 && this->player->y+my > -1 &&
		this->mWalk[this->player->y+my][this->player->x+mx] == true){
		this->player->x+=mx;
		this->player->y+=my;
	}
}

Game::Game(){
	this->player = new Player;
	player->x = 10;
	player->y = 10;
	player->Str = 5;
	player->Int = 4;
	player->Mp = 9;
	this->Map = new char*[20];
	this->mWalk = new bool*[20];

	for(int y = 0; y < 19; y++){
		this->Map[y] = new char[80];
		this->mWalk[y] = new bool[80];
		for(int x = 0; x < 80; x++){
        		this->Map[y][x] = '.';
                        this->mWalk[y][x] = true;
                }
        }
	this->Map[4][4] = '#';
	this->mWalk[4][4] = false;
	this->Map[5][4] = '#';
        this->mWalk[5][4] = false;
	this->Map[6][4] = '#';
        this->mWalk[6][4] = false;
}

