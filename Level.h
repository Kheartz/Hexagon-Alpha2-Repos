#pragma once

#include "stdafx.h"
#include "constants.h"
#include "Item.h"
#include "NPC.h"
#include "Player.h"
#include "Enemy.h"
#include "Warp.h"
#include "EntityManager.h"
#include "TextBox.h"
#include "CraftTable.h"
#include "QuestManager.h"
#include "tmx/MapLoader.h"
#include "TGUI/TGUI.hpp"

/*
Previously called Level.H in Hexagon. Had too much power. Much of it
will need to go to Obj Manager?

*/
class Area;
class Level{

private:

	sf::Texture _blackTexture;
	sf::Sprite _blackSprite;

	std::vector<Item*> items;
	std::vector<NPC*> npcs;
	std::vector<Enemy*> enemies;
	std::vector<Warp*> warps;
	std::vector<CraftTable*> craftTables;
	std::vector<sf::FloatRect*> rigids;
	
	std::vector<Area*> areas;
	Player* player;

	//Probably need a collection of GUIs
	GUI* inv;
	std::vector<GUI*> playerBar;
	sf::RenderWindow* rw;
	sf::View levelView;

	sf::FloatRect overlay;

	tmx::MapLoader maploaderr;
	sf::Event event;

	tgui::Gui gui;
	tgui::TextBox::Ptr chat;
	tgui::ListBox::Ptr promptBox;
	tgui::Grid::Ptr datgriddoe;


	lua_State* L;

public:
	Level(sf::RenderWindow* rw); //???
	
	~Level();
	void initialize();
	void setLuaState(lua_State* L){ this->L = L; }

	std::vector<Item*>& getItems(){ return items; }
	std::vector<NPC*>& getNPCs(){ return npcs; }
	std::vector<Enemy*>& getEnemies(){ return enemies; }
	Player* getPlayer() { return player; }

	
	sf::Sprite& getBlackSprite(){ return _blackSprite; }

	void setPlayer(Player* p) { player = p; }

	//Adding to Level
	void addNPC(EntityManager* em, NPC* n); 
	void addItem(EntityManager* em, Item* i); //????
	void addEnemy(EntityManager* em, Enemy* e);
	void addWarp(EntityManager* em, Warp* w);

	//Remove from Level
	void removeItem(Item* i);

	std::vector<Item*>::iterator itemIt;
	std::vector<NPC*>::iterator npcIt;
	std::vector<Enemy*>::iterator enemyIt;

	//Check for collisions
	void checkCollision(); //All Area boundaries and Body checks
	bool encapsulatedByArea(Character* c);
	bool checkCollisionBodies(Entity* c, Entity* d);
	bool checkCollisionBodies(sf::Sprite* a, sf::FloatRect* b);
	void separateBodies(Character* c, sf::FloatRect* b);

	void removeEntity(EntityManager* em, int index); //Includes All entities...Kappa

	void update();

	void setRenderWindow(sf::RenderWindow& rw){ this->rw = &rw; }
	sf::RenderWindow* getRenderWindow(){ return rw; }
	void draw();
	void pollInput(sf::Event&);
	void input();
	
	void function(const tgui::Callback& callback);
};

class Area {
private:
	sf::FloatRect rect;
public:
	Area(sf::FloatRect rect);
	sf::FloatRect& getBounds(){ return rect; }
};