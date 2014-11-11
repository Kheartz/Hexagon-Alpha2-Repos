#include "ResourceManager.h"

static ResourceManager* sharedInstance;

ResourceManager::ResourceManager(){

}

sf::Font& ResourceManager::getFont(char* name){
	//Look for the Font in the Resource Manager Font map
	for (auto it = fonts.begin(); it != fonts.end(); it++){
		if (name == (*it).first)
			return *((*it).second);
	}
	//If the Font is not in the map, create a new one.

	std::string tmpFontName("test/font/" + std::string(name) + ".ttf");
	fonts[name] = new sf::Font();
	fonts[name]->loadFromFile(tmpFontName);
	return *fonts[name];
}

ResourceManager* ResourceManager::getInstance(){
	if (!sharedInstance)
	{
		sharedInstance = new ResourceManager();
	}
	return sharedInstance;
}