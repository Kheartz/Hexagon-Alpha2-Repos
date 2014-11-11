#pragma once

#include "stdafx.h"
#include "Entity.h"
#include "ResourceManager.h"
//enum ITEM_TYPE;


class Item : public Entity{ //tolua_export
private:
	char* examine;
	std::string scriptFile;
	int id;
	bool bIsPublic;
	bool bIsQuestItem;
	bool bIsStackable;
	int numberOf;

	sf::Font numberOfTextFont; //WILL SOON BE DEPRECATED.....PLS
	sf::Text numberOfText;

public:

	enum ITEM_TYPE{
		ELEMENT,
		CONSUMABLE,
		QUEST,
	};
	ITEM_TYPE type;
	ITEM_TYPE getItemType() { return type; }


	Item(float x, float y, int w, int h, char* name, char* examine, char* filename);
	Item(char* name, char* type);
	const char* getScript(){ return scriptFile.c_str(); }
	char* getExamine(){ return examine; }
	bool isQuestItem(){ return bIsQuestItem; }
	bool isPublic(){ return bIsPublic; }
	void setPublic(bool p){ bIsPublic = p; }

	void setNumberOf(int n){ numberOf = n; }
	int getNumberOf(){return numberOf;}
	void changeNumBy(int n){ numberOf += n; }
	void incrNum(){ numberOf++; }
	void decrNum(){ numberOf--; }

	bool isStackable(){ return bIsStackable; }
	void setStackable(bool stackable){ bIsStackable = stackable; }

	sf::Text& getNumberofText(){ return numberOfText; }

};
//tolua_end