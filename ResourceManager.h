#pragma once

#include <map>
#include "SFML\Graphics.hpp"

class ResourceManager{
private:
	std::map<char*, sf::Font*> fonts;
public:
	ResourceManager();
	std::map<char*, sf::Font*>& getFonts(){ return fonts; }

	sf::Font& getFont(char* name);

	static ResourceManager* getInstance();
};