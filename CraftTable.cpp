#include "CraftTable.h"

#include <iostream>

CraftTable::CraftTable(sf::FloatRect rect, char* filename)
	:Entity(rect.left, rect.top, rect.width, rect.height, "Craft Table", filename)
{
	for (int i = 0; i < 4; i++){
		inputTable[i] = NULL;
	}
	for (int i = 0; i < 2; i++){
		resultTable[i]= NULL;
	}
	inputTableSize = 0;
	resultTableSize = 0;

}

void CraftTable::addItem(Item* i)
{
	//Search for identical items
	for (int j = 0; j < 4; j++){
		if (inputTable[j] != NULL && inputTable[j]->getName() == i->getName()){
			inputTable[j]->changeNumBy(i->getNumberOf());
			std::cout << "Added item with same name to index: " << j << std::endl;
			return;
		}
	}
	//Add in new item if no identicals
	for (int j = 0; j < 4; j++)
	{
		if (inputTable[j] == NULL){
			inputTable[j] = i;
			std::cout << "Added uniq item to index: " << j << std::endl;
			std::cout << inputTable[j]->getName() << std::endl;
			inputTableSize++;
			return;
		}
	}//I hope nothing gets deleted OpieOP

	std::cout << "Table is full. GTFO" << std::endl;
	return;
}

void CraftTable::giveResult(lua_State* L)
{
	lua_newtable(L);
	for (auto i = 0; i < inputTableSize; i++){
		tolua_pushstring(L, inputTable[i]->getName());
		tolua_pushnumber(L, inputTable[i]->getNumberOf());
		lua_settable(L, -3);
	}
	lua_setglobal(L, "inputCraftTable");

	luaL_dofile(L, "test/script/recipe.lua");


}

void CraftTable::status()
{

}