#pragma once

#include "stdafx.h"
#include "Entity.h"
#include "NPC.h"
#include "Item.h"

class EntityManager{ //tolua_export
private:
	int _index;
	std::map <int, Entity*> list;
	
public: 
	//tolua_begin
	EntityManager();
	~EntityManager();
	
	void Add(Entity*);
	void Remove(int index);
	
	int getIndex()	{ return _index; }
	int getIndex(char* name);
	NPC* getNPC(char* name);
	Item* getItem(char* name);
	int getSize() { return list.size(); }
	std::map<int, Entity*>& getList(){ return list; }

	static EntityManager* getInstance();
};
//tolua_end

