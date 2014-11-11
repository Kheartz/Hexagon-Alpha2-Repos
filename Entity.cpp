#pragma once

#include "Entity.h"
#include <iostream>

Entity::Entity(float X, float Y, int W, int H, char* name2, char* filename){
	alpha = 0;

	if (filename != "")
	{
		_image.loadFromFile(filename);


		
		_image.createMaskFromColor(sf::Color(255, 0, 255));
		_texture.loadFromImage(_image);
		_sprite.setTexture(_texture);
		_sprite.setTextureRect(sf::IntRect(0, 0, W, H));
		_sprite.setPosition(X, Y);
	}
	if (name2 != NULL)
		this->name = name2;

	frame = 0;
	maxFrames = 0; //maxframe = XClips*YClips

	xFrame = 0;
	yFrame = 0;
	
}

void Entity::setHardPosition(float x, float y){
	_sprite.setPosition(x, y);
}

void Entity::move(float x, float y){
	_sprite.move(x, y);
}

void Entity::changeAlpha(int del){
	_texture.loadFromImage(_image);
	_sprite.setColor(sf::Color(255, 255, 255, alpha + del));
	_sprite.setTexture(_texture);
	alpha += del;
}

sf::Sprite& Entity::getSprite(){
	return _sprite; 
}



