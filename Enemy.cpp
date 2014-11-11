#include "Enemy.h"
#include <iostream>
Enemy::Enemy(float X, float Y, int W, int H, char* name, int HP, int MP, char* filename) :
NPC(X, Y, W, H, name, HP, MP, filename){
	//get fucked.
	HPBar = new GUI(this->getX(), this->getY() - 10, this->getW(), 5, "test/misc/hpbar.png", 255, false);
	MPBar = new GUI(this->getX(), this->getY() - 5, this->getW(), 3, "test/misc/mpbar.png", 255, false);


}

Enemy::~Enemy(){
	delete HPBar;
	delete MPBar;
}

void Enemy::update(){

	if (xVel != 0)
		xFrame++;
	else if (yVel != 0)
		yFrame++;


	this->HPBar->setHardPosition(this->getX(), this->getY() - 10);
	this->MPBar->setHardPosition(this->getX(), this->getY() - 5);

	this->move(xVel, yVel);
}