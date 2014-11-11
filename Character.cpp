#include "Character.h"
#include <iostream>

Character::Character(float X, float Y, int W, int H, char* name, int Hp, int Mp, char* filename)
	: Entity(X, Y, W, H, name, filename)
{
	direction = RIGHT;
	isMoving = false;
	xVel = 0;
	yVel = 0;
	level = 1;
	this->HP = Hp;
	this->MP = Mp;

	frame = 0;
	std::string filename_(filename);

	std::string tmp = filename_.substr(0, filename_.size() - 4);
	_imageD.create(_image.getSize().x, _image.getSize().y / 4);
	_imageU.create(_image.getSize().x, _image.getSize().y / 4);
	_imageL.create(_image.getSize().x, _image.getSize().y / 4);
	_imageR.create(_image.getSize().x, _image.getSize().y / 4);

	_imageD.copy(_image, 0, 0, sf::IntRect(0,				0,			  _image.getSize().x, _image.getSize().y / 4));
	_imageU.copy(_image, 0, 0, sf::IntRect(0, 1 * _image.getSize().y / 4, _image.getSize().x, _image.getSize().y / 4));
	_imageL.copy(_image, 0, 0, sf::IntRect(0, 2 * _image.getSize().y / 4, _image.getSize().x, _image.getSize().y / 4));
	_imageR.copy(_image, 0, 0, sf::IntRect(0, 3 * _image.getSize().y / 4, _image.getSize().x, _image.getSize().y / 4));

	_textureD.loadFromImage(_imageD);
	_textureU.loadFromImage(_imageU);
	_textureL.loadFromImage(_imageL);
	_textureR.loadFromImage(_imageR);

}
void Character::changeHP(int INCHP)
{
	HP += INCHP;
	if (HP>MaxHP)HP = MaxHP;
	if (HP<0)HP = 0;
}
void Character::changeMP(int INCMP)
{
	MP += INCMP;
	if (MP>MaxMP)MP = MaxMP;
	if (MP<0)HP = 0;
}
void Character::setHP(int Hp)
{
	HP = Hp;
}
void Character::setMP(int Mp)
{
	MP = Mp;
}
int Character::getHP()
{
	return HP;
}
int Character::getMP()
{
	return MP;
}

void Character::move(float x, float y){
	_sprite.move(x, y);
}

sf::Sprite& Character::getSprite(){
	
	switch (this->direction){
	case(Character::FACING_DIRECTION::DOWN) :
		_sprite.setTextureRect(sf::IntRect(yFrame*getW() % _textureD.getSize().x, 0, getW(), getH()));
		_sprite.setTexture(_textureD);
		return _sprite; 
		break;
	case(Character::FACING_DIRECTION::UP) :
		_sprite.setTextureRect(sf::IntRect(yFrame*getW() % _textureU.getSize().x, 0, getW(), getH()));
		_sprite.setTexture(_textureU);  
		return _sprite; 
		break;
	case(Character::FACING_DIRECTION::LEFT) :
		_sprite.setTextureRect(sf::IntRect(xFrame*getW() % _textureL.getSize().x, 0, getW(), getH()));
		_sprite.setTexture(_textureL);  
		return _sprite; 
		break;
	case(Character::FACING_DIRECTION::RIGHT) :
		_sprite.setTextureRect(sf::IntRect(xFrame*getW() % _textureR.getSize().x, 0, getW(), getH()));
		_sprite.setTexture(_textureR); 
		//_sprite.setTextureRect(sf::IntRect(xFrame*getW() % _textureR.getSize().x, yFrame*getH(), getW(), getH()));  
		return _sprite; 
		break;
	//case(Character::FACING_DIRECTION::RIGHT) :   return _sprite; break;
	}
	return _sprite;
	//_sprite.setTextureRect(sf::IntRect(xFrame*getW() % 96, xFrame*getH() % 192, getW(), getH()));
}