#pragma once

#include "EntityManager.h"
#include "Player.h"
#include "Character.h"
#include  "GUI.h"
#include "Item.h"
#include "stdafx.h"
#include "Timer.h"
#include "NPC.h"
#include "Enemy.h"
#include "Level.h"
#include "QuestManager.h"
#include "CraftTable.h"
#include "tolua_EntityManager.h"
#include "tolua_Entity.h"
#include "tolua_Character.h"
#include "tolua_NPC.h"
#include "tolua_Player.h"
#include "tolua_Item.h"
#include "tolua_CraftTable.h"
#include "tolua_Quest.h"
#include "tolua_QuestManager.h"

enum GAMESTATE;
class Game{
private:

	sf::Event event;
	lua_State* L;
	enum GAMESTATE{
		_SPLASH,
		GAME,
		PAUSED,
	};

public:
	void run();
	void GameLoop();
	void initilizeLua();
	void initilizeQuests();
	void setLuaGlobals();
	void input(sf::Event event);

	sf::RenderWindow mainWindow;
};

