#pragma once
#include "stdafx.h"

class Sprite {
private:
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Sprite();
	Sprite(std::string filename);
	Sprite(std::string filename, int alpha);

	void changeAlphaBy(int delta);

	sf::Sprite& getSprite(){ return _sprite; }
	

};