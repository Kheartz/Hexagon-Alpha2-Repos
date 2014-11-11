#pragma once

#include "NPC.h"

class Enemy : public NPC {
private:
	GUI* HPBar;
	GUI* MPBar;

	Character* targetCharacter;

	
public:
	Enemy(float X, float Y, int W, int H, char* name, int HP, int MP, char* filename);
	Enemy(sf::FloatRect, char* name, int HP, int MP, char* filename);
	~Enemy();
	GUI* getHPBar() { return HPBar; }
	GUI* getMPBar() { return MPBar; }
	
	void update();

};