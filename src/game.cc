#include<game.h>
#include<screen.h>


void Game::OpenClose(int x, int y){
	if(this->map[y][x].door && this->map[y][x].walk != true){
		this->map[y][x].c='\'';
		this->map[y][x].walk = true;
	} else if(this->map[y][x].door){
		this->map[y][x].c='+';
		this->map[y][x].walk = false;
	} else{
		return;
	}
}

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
		case 'O':
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
		this->map[this->player->y+my][this->player->x+mx].walk == true){
		this->player->x+=mx;
		this->player->y+=my;
	} else if(this->map[this->player->y+my][this->player->x+mx].door){
		this->OpenClose(this->player->x+mx, this->player->y+my);
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
	this->map = new Tile*[20];
	for(int y = 0; y < 19; y++){
		this->Map[y] = new char[80];
		this->mWalk[y] = new bool[80];
		this->map[y] = new Tile[80];
		for(int x = 0; x < 80; x++){
        		this->Map[y][x] = '.';
                        this->mWalk[y][x] = true;
			this->map[y][x].c = '.';
			this->map[y][x].walk = true;
                }
        }
	this->map[4][4].c = '+';
	this->map[4][4].walk = false;
	this->map[4][4].door = true;
        this->map[5][4].c = '+';
        this->map[5][4].walk = false;
        this->map[5][4].door = true;
        this->map[4][5].c = '+';
        this->map[4][5].walk = false;
        this->map[4][5].door = true;
        this->map[4][6].c = '+';
        this->map[4][6].walk = false;
        this->map[4][6].door = true;
        this->map[6][4].c = '+';
        this->map[6][4].walk = false;
        this->map[6][4].door = true;
        this->map[6][5].c = '+';
        this->map[6][5].walk = false;
        this->map[6][5].door = true;
        this->map[6][6].c = '+';
        this->map[6][6].walk = false;
        this->map[6][6].door = true;
        this->map[6][6].c = '+';
        this->map[6][6].walk = false;
        this->map[6][6].door = true;
        this->map[5][6].c = '+';
        this->map[5][6].walk = false;
        this->map[5][6].door = true;

}



