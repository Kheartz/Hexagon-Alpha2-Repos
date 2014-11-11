#pragma once

#include "stdafx.h"
#include "Character.h"
#include  "NPC.h"
#include "Item.h"
#include "EntityManager.h"

class Player : public Character{ //tolua_export
private:
protected:
	int monies;
	int XP;
	int MaxXP;

	//std::/vector<Item*> inventory(20);
	Item* inventory[45];
	int maxInvSize;
	int invSize;
	bool invActive;

	float maxVel; 

	NPC* targetNPC;
	/*
	Item* Head;
	Item* Torso;
	Item* Gloves;
	Item* Legs;
	Item* Feet;
	Item* Necklace;
	Item* RightHand;
	Item* LeftHand;
	*/

public:
	Item** getInv() { return inventory; }
	//tolua_begin
	Player(float X, float Y, int W, int H, char* name, int MAXHP, int MAXMP, char* filename);
	

	//void equip(Item* incItem);
	
	/*
	Player* getInstance();
	NPC* getTargetNPC(){ return targetNPC; }
	void setTargetNPC(NPC* target){ targetNPC = target; }
	*/
	void setMonies(int m){ monies = m; }
	int getMonies(){ return monies; }

	void addItem(Item* i);
	void removeItem(int index);

	void setXP(int e){ XP = e; }
	void incXP(int e){ XP += e; }
	void setLevel(int e){ level = e; }
	int getXP() { return XP; }
	int getMaxXP() { return MaxXP; }
	void setMaxXP(int xp){ MaxXP = xp; }
	int getLevel(){ return level; }
	void incLevel(){ level++; }
	
	float getMyMaxVel(){ return maxVel; }

	//void procKill(Enemy* enemy);

	void setTargetNPC(NPC* n){ targetNPC = n; }
	NPC* getTargetNPC() { return targetNPC; }
	void unTargetNPC(){ targetNPC = NULL; }
	
	
	int getInvSize() { return invSize; }
	bool isInvFull() { return invSize == maxInvSize; }
	void toggleInventory();

	//map<string, Quest*> questLog;

	//vector<SpellInfo*> spellBook;

	void useItem(lua_State* L, Item* i);



};
//tolua_end

