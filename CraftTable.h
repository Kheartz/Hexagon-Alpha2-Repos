#pragma once

#include "Entity.h"
#include "tolua.h"
#include "Item.h"
#include "GUI.h"



class CraftTable : public Entity{//tolua_export
private:
	GUI craftBoxMenu;
	Item* inputTable[4];
	int inputTableSize;
	Item* resultTable[2];
	int resultTableSize;

public:
	
	CraftTable(sf::FloatRect, char* filename);

	void addItem(Item* i);
	Item* removeItem();
	
	GUI getCraftBoxMenu() { return craftBoxMenu; }
	Item** getInputTable(){ return inputTable; }
	int getInputTableSize(){ return inputTableSize; }
	Item** getResultTable() { return resultTable; }
	int getResultTableSize(){ return resultTableSize; }

	void status();

	void giveResult(lua_State* L);

	//tolua_begin

	
};
//tolua_end

