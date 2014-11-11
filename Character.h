#pragma once

#include "stdafx.h"
#include "Entity.h"

class Character : public Entity{ //tolua_export
private:
protected:
	int HP;
	int MP;
	int MaxHP;
	int MaxMP;
	int level;
	int index;
	float xVel;
	float yVel;

	sf::Image _imageU;
	sf::Image _imageD;
	sf::Image _imageL;
	sf::Image _imageR;

	sf::Texture _textureU;
	sf::Texture _textureD;
	sf::Texture _textureL;
	sf::Texture _textureR;

public:
	//tolua_begin
	Character(float X, float Y, int W, int H, char* name, int Hp, int Mp, char* filename);
	Character(sf::FloatRect fRect, char* name, int Hp, int Mp, char* filename);
	
	float getXVel() { return xVel; }
	float getYVel() { return yVel; }
	void setXVel(float xvel){ xVel = xvel; }
	void setYVel(float yvel){ yVel = yvel; }
	void incXVel(float xvel){ xVel += xvel; }
	void incYVel(float yvel){ yVel += yvel; }

	virtual void setName(char* n) { name = n; }
	virtual void setHP(int);
	virtual void setMP(int);
	virtual int getMaxHP(){ return MaxHP; }
	virtual int getMaxMP(){ return MaxMP; }
	void changeHP(int);
	void changeMP(int);
	virtual int getHP();
	virtual int getMP();
	void setMaxHP(int MHP){ MaxHP = MHP; }
	void setMaxMP(int MMP){ MaxMP = MMP; }

	
	enum FACING_DIRECTION{
		LEFT,
		RIGHT,
		DOWN,
		UP
	};
	FACING_DIRECTION direction;
	FACING_DIRECTION getDir(){ return direction; }
	virtual void setDir(FACING_DIRECTION fd) { direction = fd; }
	virtual void move(float x, float y);

	virtual sf::Sprite& getSprite();

	

	bool isMoving;

};
//tolua_end