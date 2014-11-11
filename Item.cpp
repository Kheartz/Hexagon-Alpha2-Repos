#include "Item.h"
#include <iostream>

/*Item::Item(char* filename) : Entity()
{
	//Open a file name...read through for name and examine
	//Too lazy to do now...
}
*/
Item::Item(float x, float y, int w, int h, char* name, char* examine, char* filename)
	: Entity(x, y, w, h, name, filename)
{
	bIsPublic = true;
	this->examine = examine;
	
	std::string tmp = name;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	scriptFile = "test/script/" + tmp + ".lua";
	bIsStackable = true;
	numberOf = 1;

	/*numberOfTextFont.loadFromFile("test/font/arial.ttf");*/
	//numberOfText.setFont(numberOfTextFont);
	numberOfText.setFont(ResourceManager::getInstance()->getFont("arial"));
	numberOfText.setCharacterSize(16);
	//numberOfText.setString(std::to_string(0));

}

Item::Item(char* name, char* typeName)
	: Entity(0, 0, 32, 32, name, "")
{
	bIsPublic = true;
	this->examine = "This has no examine.";
	//setHardPosition(rand() % 600 + 20, rand() % 800 + 69);
	std::string tmp = name;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	scriptFile = "test/script/" + tmp + ".lua";
	std::string filename = "test/item/element/" + tmp + ".png";

	_image.loadFromFile(filename);

	_image.createMaskFromColor(sf::Color(255, 0, 255));
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	std::string typetmp(typeName);

	std::transform(typetmp.begin(), typetmp.end(), typetmp.begin(), ::tolower);

	if (typetmp == "quest")
		type = ITEM_TYPE::QUEST;
	else if (typetmp == "consumable")
		type = ITEM_TYPE::CONSUMABLE;
	else if (typetmp == "element")
		type = ITEM_TYPE::ELEMENT;
	else
		type = ITEM_TYPE::CONSUMABLE;

	bIsStackable = true;
	numberOf = 1;

	numberOfText.setFont(ResourceManager::getInstance()->getFont("arial"));
	numberOfText.setCharacterSize(16);
}
