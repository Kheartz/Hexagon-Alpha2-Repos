#include "EntityManager.h"
#include <iostream>

static EntityManager* sharedInstance;

EntityManager::EntityManager(){
	_index = 0; 
}
EntityManager::~EntityManager(){
	for (auto it : list)
		delete it.second;
}

void EntityManager::Add(Entity* e){
	list.insert(std::pair<int, Entity*>(_index, e));
	e->setIndex(_index);
	_index++;

}

int EntityManager::getIndex(char* name){
	for (auto it : list){
		if (!strcmp(name, it.second->getName()))
			return it.first;
	}
	std::cout << "Index not found" << std::endl;
	return -1;
}

NPC* EntityManager::getNPC(char* name)
{
	for (auto it : list){
		if (!strcmp(name, it.second->getName()))
			return (NPC*)(it.second);
	}
	std::cout << "Index not found" << std::endl;
	return NULL;
}
Item* EntityManager::getItem(char* name)
{
	for (auto it : list){
		//if (it->second->getName() == name)
		if (!strcmp(name, it.second->getName()))
			return (Item*)(it.second);
	}
	std::cout << "Index not found" << std::endl;
	return NULL;
}


void EntityManager::Remove(int index){
	list.erase(index);
}

EntityManager* EntityManager::getInstance(){
	if (!sharedInstance)
	{
		sharedInstance = new EntityManager();
	}
	return sharedInstance;
}