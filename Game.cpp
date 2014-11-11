
#include "Game.h"
#include <iostream>
#include "TGUI/TGUI.hpp"
void Game::run(){

	L = luaL_newstate();
	initilizeLua();
	setLuaGlobals();


	srand((unsigned int)time(NULL));

	sf::RenderWindow mainWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Alchemist 0.01a Kappa");
	sf::View view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	mainWindow.setView(view);
	mainWindow.setFramerateLimit(60);
	sf::Texture loadingTexture;
	loadingTexture.loadFromFile("test/loading.png");
	sf::Sprite loadingSprite;
	mainWindow.clear();

	mainWindow.draw(loadingSprite);
	//EVERYTHING WILL BE ADDED THROUGH LEVEL -- script?

	Player myPlayer(10, 101, 96 / 3, 192 / 4, 0, 100, 200, "test/character/elliot.png");
	tolua_pushusertype(L, &myPlayer, "Player");
	lua_setglobal(L, "player");

	Level myLevel(&mainWindow);
	myLevel.setPlayer(&myPlayer);
	myLevel.initialize();
	myLevel.setLuaState(L);
	tgui::Gui gui2(mainWindow);
	gui2.setGlobalFont("test/font/arial.ttf"); 
	tgui::TextBox textBox;
	textBox.setPosition(0, 0);
	initilizeQuests();

	while (mainWindow.isOpen()){
		while (mainWindow.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				mainWindow.close();
			if (event.key.code == sf::Keyboard::K){

				//ct.addItem(myPlayer.getInv()[0]);
				//myPlayer.useItem(L, myPlayer.getInv()[0]);
			}
			if (event.key.code == sf::Keyboard::M){
				//ct.giveResult(L);
				/*if (luaL_dofile(L, "test/script/recipe.lua")) {
					//execute the file
					const char* err = lua_tostring(L, -1); // if there was an issue, get the string from the top of the stack...
					printf(err); // ...and print it out
				}*/
			}

			myLevel.pollInput(event);
			gui2.handleEvent(event);
		}
		mainWindow.clear();
		myLevel.input();
		myLevel.checkCollision();
		myLevel.update();
		myLevel.draw();
	}
	lua_close(L); //close the lua state
	delete EntityManager::getInstance(); //Place holder. Eventually, I will need to clear all objects.
	delete QuestManager::getInstance();
}

void Game::GameLoop(){
}


void Game::initilizeLua()
{
	std::cout << "Opening Lua and ToLua Libraries..." << std::endl;
	luaL_openlibs(L); //open the default Lua libraries
	tolua_open(L);
	tolua_EntityManager_open(L);
	tolua_Entity_open(L);
	tolua_Character_open(L);
	tolua_NPC_open(L);
	tolua_Player_open(L);
	tolua_Item_open(L);
	tolua_Quest_open(L);
	tolua_QuestManager_open(L);
	std::cout << "Lua and ToLua Libraries initlialized..." << std::endl;
}
void Game::setLuaGlobals()
{
	QuestManager* qm = QuestManager::getInstance();
	tolua_pushusertype(L, qm, "QuestManager");
	lua_setglobal(L, "qm");
	EntityManager* em = EntityManager::getInstance();
	tolua_pushusertype(L, em, "EntityManager");
	lua_setglobal(L, "em");
}
void Game::initilizeQuests()
{
	if (luaL_dofile(L, "test/quest/testquest.lua")) {
		//execute the file
		const char* err = lua_tostring(L, -1); // if there was an issue, get the string from the top of the stack...
		printf(err); // ...and print it out
	}
	if (luaL_dofile(L, "test/quest/Carbon, Where Art Thou.lua")) {
		//execute the file
		const char* err = lua_tostring(L, -1); // if there was an issue, get the string from the top of the stack...
		printf(err); // ...and print it out
	}
	
	if (luaL_dofile(L, "test/quest/House of Hermes.lua")) {
		//execute the file
		const char* err = lua_tostring(L, -1); // if there was an issue, get the string from the top of the stack...
		printf(err); // ...and print it out
	}
}