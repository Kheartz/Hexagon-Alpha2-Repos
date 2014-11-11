#include "Player.h"
#include <iostream>
Player::Player(float X, float Y, int W, int H, char* name, int MAXHP, int MAXMP, char* filename)
	: Character(X, Y, W, H, name, 0, 0, filename)
{
	
	MaxHP = MAXHP;
	HP = MaxHP;
	MaxMP = MAXMP;
	MP = MaxMP;
	MaxXP = 100;
	XP = 20;
	MaxHP = 100;
	level = 1;

	monies = 1500;

	invSize = 0;
	maxInvSize = 50;
	invActive = true;

	maxVel = 2.5;

	for (int i = 0; i < maxInvSize; i++)
		inventory[i] = NULL;

/*	Head = NULL;
	Torso = NULL;
	Gloves = NULL;
	Legs = NULL;
	Feet = NULL;
	Necklace = NULL;
	LeftHand = NULL;
	RightHand = NULL;


	spellBook.push_back(new SpellInfo("Ice Frost", 17, eIce, 5));*/

	targetNPC = NULL;

	addItem(new Item(60, 60, 32, 32, "Potion", "Increases your Health by 100.", "test/item/gPotion.png"));
	addItem(new Item(60, 60, 32, 32, "Mana", "Increases your Mana by 100.", "test/item/gManaPotion.png"));
	addItem(new Item(60, 60, 32, 32, "Carbon", "Atomic No. 6.", "test/item/element/carbon.png"));
	addItem(new Item(60, 60, 32, 32, "Oxygen", "Atomic No. 8.", "test/item/element/oxygen.png"));
	addItem(new Item(420, 69, 32, 32, "Hydrogen", "Atomic No. 1", "test/item/element/hydrogen.png"));
}


void Player::addItem(Item* i){
	//inventory.push_back(i);
	for (int j = 0; j < invSize; j++){
	//	std::cout << i->getName() << " " << inventory[j]->getName() << std::endl;
		//Need to cast them to strings to have them equal each other. Lua string to char* doesn't seem to work.
		if (std::string(i->getName()) == std::string(inventory[j]->getName()) && i->isStackable())
		{
	//		std::cout << inventory[j]->getNumberOf() << std::endl;
			inventory[j]->incrNum();
			EntityManager::getInstance()->Remove(i->getIndex());
	//		std::cout << inventory[j]->getNumberOf() << std::endl;
			return;
		}
	}
	if (invSize < 45){
		inventory[invSize] = i;
		inventory[invSize]->setHardPosition((float)((invSize % 4)*getW()), (float)(invSize / 4 * i->getH()));
		invSize++;
	}
	else
	{
		delete i;
	}
	
}

void Player::removeItem(int index){ //index = 15; size 16
	EntityManager::getInstance()->Remove(index);
	//if (index < inventory.size())
	//	inventory.erase(inventory.begin()+index);
	//if (index < invSize)
		//return inventory[index];

}

void Player::useItem(lua_State* L, Item* i){
	luaL_dofile(L, i->getScript());
	for (int j = 0; j < invSize; j++){
		if (i == getInv()[j])
			index = j;
	}
	i->decrNum();
	if (i->getNumberOf() <= 0){
		for (int j = index + 1; j < invSize; j++){
			inventory[j - 1] = inventory[j];
		}
		inventory[invSize - 1] = NULL;
		invSize--;
	}
}

void Player::toggleInventory(){
	if (invActive)
		invActive = false;
	else if (!invActive)
		invActive = true;
}