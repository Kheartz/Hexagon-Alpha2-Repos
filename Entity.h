#pragma once

#include "stdafx.h"


class Entity{ //tolua_export
private:

protected:
	sf::Image _image;
	sf::Texture _texture;
	std::vector<sf::Texture> FTextures; //Character .png files will be parsed into a collection of sprites
	sf::Sprite _sprite;
	
	std::string name;
	
	int alpha; //opacity of object
	bool bIsSolid;
	int frame; //Current frame on animation sheet?
	int maxFrames; //Number of total clips/frames on the sheet

	int index;

	//sf::FloatRect rigidBody;

public:
	//tolua_begin
	Entity(float x, float y, int w, int h, char* name, char* filename);
	Entity(sf::FloatRect fRect, char* name, char* filename);

	virtual sf::Sprite& getSprite();

	virtual float getX(){ return _sprite.getPosition().x; }
	virtual float getY(){ return _sprite.getPosition().y; }
	virtual const int getW(){ return _sprite.getTextureRect().width; }
	virtual const int getH(){ return _sprite.getTextureRect().height; }
	
	virtual char* getName(){ return (char*)name.c_str(); }


	int xFrame;
	int yFrame;
	/*	float getX();
	float getY();
	const int getW();
	const int getH();*/

	virtual int getCurFrame() { return frame; }
	virtual void incFrame(){ frame++; }
	virtual void decFrame(){ frame--; }


	virtual bool isSolid(){ return bIsSolid; }
	virtual void setHardPosition(float x, float y); //Warp
	virtual void move(float x, float y); //Displacement
	virtual void changeAlpha(int del);

	virtual void setIndex(int index){ this->index = index; }
	virtual int getIndex() { return index; }

	
};
//tolua_end